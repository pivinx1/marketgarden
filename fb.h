#ifndef _FB_H
#define _FB_H

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

void fb_move_cursor(unsigned short pos);

void clear_screen();

void fb_crlf();

void print(char* buf);

#endif 

