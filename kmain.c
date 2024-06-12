/* haha imagine having libraries, can't be me */
#include "fb.h"

void kmain()
{
	fb_write_cell(0, 'P', 15, 3);
	fb_write_cell(2, 'I', 15, 3);
	fb_write_cell(4, 'S', 15, 3);
	fb_write_cell(6, 'S', 15, 3);
}

int sum_of_three(int arg1, int arg2, int arg3) 
{
  return arg1 + arg2 + arg3;    // try pooping
}
