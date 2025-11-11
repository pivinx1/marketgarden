#include "fb.h"
#include "io.h"
#include "string.h"


static inline unsigned char vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}

static inline unsigned short vga_entry(unsigned char uc, unsigned char color) 
{
	return (unsigned short) uc | (unsigned short) color << 8;
}

static const unsigned int VGA_WIDTH = 80;
static const unsigned int VGA_HEIGHT = 25;

unsigned int terminal_row;
unsigned int terminal_column;
unsigned char terminal_color;
unsigned short* terminal_buffer;

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (unsigned short*) 0xB8000;
	for (unsigned int y = 0; y < VGA_HEIGHT; y++) {
		for (unsigned int x = 0; x < VGA_WIDTH; x++) {
			const unsigned int index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(unsigned char color) 
{
	terminal_color = color;
}

void terminal_putentryat(char c, unsigned char color, unsigned int x, unsigned int y) 
{
	const unsigned int index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_scroll(void)  
{
    // Scroll the buffer up by one row.
    const unsigned int buffer_size = (VGA_HEIGHT - 1) * VGA_WIDTH;

    memmove(terminal_buffer, terminal_buffer + VGA_WIDTH, buffer_size * 2);

    // Clear the last row.
    const unsigned int last_row_offset = VGA_HEIGHT - 1;
    for (unsigned int x = 0; x < VGA_WIDTH; x++) {
        terminal_putentryat(' ', terminal_color, x, last_row_offset);
    }
}

void terminal_putchar(char c) 
{
	switch (c) {
		case '\n':
			if (terminal_row + 1 == VGA_HEIGHT) {
                  terminal_scroll();
                  terminal_column = 0;
            } else {
                terminal_row++;
                terminal_column = 0;
            }
            break;
		default:
			terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
			if (++terminal_column == VGA_WIDTH) {
		        terminal_column = 0;
		        if (++terminal_row == VGA_HEIGHT)
			        terminal_row = 0;
	        }
			break;
	}

}

void terminal_write(const char* data, unsigned int size) 
{
	for (unsigned int i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}

void kprint(const char* data)
{
	terminal_writestring(data);
}

