/* haha imagine having libraries, can't be me */
#include "fb.h"
#include "io.h"
#include "serial.h"

#define COM1 0x3F8

void kmain()
{
	initialize_serial(COM1);
	clear_screen();
	print("MarketGardenOS 0.0.1 powered by DuctTape Kernel");
	print("Initializing...");
	write_serial(COM1, 'P');
	write_serial(COM1, 'i');
	write_crlf_serial(COM1);
	write_serial(COM1, 's');
	write_serial(COM1, 's');
	print("\nDone!\n");
	print("Halting...");
}
