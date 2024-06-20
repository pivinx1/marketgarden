global outb
global inb

; outb: send byte to specifed I/O port
; stack: [esp + 8] - data byte
; 	 [esp + 4] - I/O port
;	 [esp    ] - return address

outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret

; inb: grab a byte from specified I/O port (pun not intended)
; stack: [esp + 4] - I/O port we grab a byte from
;	 [esp	 ] - the return address

inb:
	mov dx, [esp + 4] ; put the port in the DX register
	in  al, dx	  ; grab the byte from the port and put it in the AL register
	ret		  ; return whatever we found there
