#ifndef SERIAL_H
#define SERIAL_H

void configure_baud_rate(unsigned short com, unsigned short divisor);

void configure_line(unsigned short com);

void configure_buffers(unsigned short com);

void configure_modem(unsigned short com);

int is_transmit_fifo_empty(unsigned short com);

void initialize_serial(unsigned short com);

void write_serial(unsigned short com, char a);

void write_crlf_serial(unsigned short com);

void kprint_serial(char* buf, unsigned short com);

#endif
