/* haha imagine having libraries, can't be me */
#include "fb.h"
#include "io.h"
#include "serial.h"

#define COM1 0x3F8

void kmain()
{
	initialize_serial(COM1);
	clear_screen();
	print("MarketGardenOS 0.0.1 powered by DuctTape Kernel\n");
	print("Initializing...\n");
	print("Debug output active on COM1, 9600-8-N-1\n");
	print_serial("[INFO] Serial log active\n", COM1);
	print_serial("[INFO] kmain execution complete\n", COM1);
}
