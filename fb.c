#include "fb.h"
#include "io.h"

/* Framebuffer I/O ports */
#define FB_COMMAND_PORT	0x3D4
#define FB_DATA_PORT	0x3D5

/* I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

char *fb = (char *) 0x000B0000;

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
	fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/*
 * fb_move_cursor
 * Move framebuffer cursor to specified position.
 *
 * @param pos	New position of cursor on screen
 */

void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT,    pos & 0x00FF);
}

void clear_screen()
{
	for (int i = 0; i < FB_CELLS, i++)
		fb_write_cell(i, ' ', 0, 0)
}
