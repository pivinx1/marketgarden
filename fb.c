#include "fb.h"
#include "io.h"

/* Framebuffer colors (currently static, for printf) */
#define FB_FOREGROUND 7	/* light gray on... */
#define FB_BACKGROUND 0 /* ...a black background */

/* Framebuffer sizing  */
#define FB_COLUMNS 	80
#define FB_ROWS		25
#define FB_CELLS	FB_COLUMNS * FB_ROWS

/* Framebuffer I/O ports */
#define FB_COMMAND_PORT	0x3D4
#define FB_DATA_PORT	0x3D5

/* I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

char *fb = (char *) 0xB8000;
unsigned short mem_pos = 0;

/*
 *
 * fb_write_cell:
 * Write a character with specified foreground and background to a place in the framebuffer.
 * @param i - Framebuffer offset
 * @param c - Character to put in framebuffer
 * @param fg - Foreground color
 * @param bg - Background color
 *
 */

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
	fb[i] = c;
	fb[i + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

/*
 * fb_move_cursor
 * Move framebuffer cursor to specified position.
 *
 * @param x	location of cursor on X axis
 * @param y	location of cursor on Y axis
 */

void update_cursor(int x, int y)
{
	unsigned short pos = y * FB_COLUMNS + x;

	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT,    pos & 0x00FF);
}

void clear_screen()
{
	for (int i = 0; i < FB_CELLS; i += 2)
		fb_write_cell(i, ' ', 0, 0);
}

void fb_crlf()
{
	fb_write_cell(mem_pos, 0xD, 0, 0);
}

void print(char* buf)
{
	int n = 0;
	while(buf[n] != 0)
		n++;
	int size = n;
	for (int i = 0; i < size; i++)
	{
		switch (buf[i])
		{
			case '\n':
				fb_crlf();
				break;
			default:
				fb_write_cell(mem_pos, buf[i], FB_FOREGROUND, FB_BACKGROUND);
				break;
		}
		mem_pos += 2;
	}
}
