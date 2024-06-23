#include "io.h"
#include "serial.h"

#define SERIAL_COM1_BASE	0x3F8

#define CR			0xD
#define LF			0xA

#define SERIAL_DATA_PORT(base)			(base)
#define SERIAL_FIFO_COMMAND_PORT(base)		(base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)		(base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base)		(base + 4)
#define SERIAL_LINE_STATUS_PORT(base)		(base + 5)

#define SERIAL_LINE_ENABLE_DLAB			0x80



void configure_baud_rate(unsigned short com, unsigned short divisor)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void configure_line(unsigned short com)
{
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03); /* 8 bits, no parity, one stop, no break control */
}

void configure_buffers(unsigned short com)
{
	outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
	/* enable FIFO, clear both queues, and use 14 B as queue size */
}

void configure_modem(unsigned short com)
{
	outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
	/* don't enable interrupts since we don't receive, we are ready to transmit and our data terminal is ready */
}

void initialize_serial(unsigned short com)
{
	configure_baud_rate(com, 12); /* 115200 / 12 = 9600 */
	configure_line(com);
	configure_buffers(com);
	configure_modem(com);
}

int is_transmit_fifo_empty(unsigned short com)
{
	/* 0x20 is 0010 0000 */
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void write_crlf_serial(unsigned short com)
{
	write_serial(com, CR);
	write_serial(com, LF);
}

void write_serial(unsigned short com, char a)
{
	while(is_transmit_fifo_empty(com) == 0);

	outb(com, a);		
}
