global outb

; outb: send byte to specifed I/O port
; stack: [esp + 8] - data byte
; 	 [esp + 4] - I/O port
;	 [esp    ] - return address

outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret
