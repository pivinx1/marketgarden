#include "fb.h"

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
