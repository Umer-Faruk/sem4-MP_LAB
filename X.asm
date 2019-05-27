assume cs:code
code segment
start:
	;mov ah,00h
	;mov al,02h
	mov ax,0002h
	int 10h

	mov ah,02

	;mov dh,12d
	;mov dl,25d
	mov dx,1205d
	int 10h
	
	
	mov al,'X'
	mov bl,8eh
	mov cl,1
	mov ah,9
	int 10h

	mov ah,4ch
	int 21h
code ends
end start
