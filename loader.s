global loader                   ; the entry symbol for ELF
extern kmain           		; main is definitely somewhere else, but idk where

MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)
KERNEL_STACK_SIZE equ 4096
section .multiboot
align 4
	dd MAGIC_NUMBER
	dd FLAGS
	dd CHECKSUM

section .text:                  ; start of the text (code) section
align 4                         ; the code must be 4 byte aligned
    dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum

section .bss:
align 4
kernel_stack:
  resb KERNEL_STACK_SIZE        ; make a 4 kB large stack

loader:                         ; the loader label (defined as entry point in linker script)
    mov eax, 0xDEADBEEF         ; place the number 0xDEADBEEF in the register eax (not gonna be doing anything with it, just let it be there)
                                ; it will be overwritten by C anyways
    mov esp, kernel_stack + KERNEL_STACK_SIZE ; ask the CPU to put the stack pointer in the start of the stack

    call kmain               
    
    
.loop:
    jmp .loop                   ; loop forever
