assume cs:code
code segment
start:
	
	mov ah,2ch
	int 21h
	


	mov al,ch
	aam
	add ax,3030h
	mov bx,ax
	call d
	
	mov dl,':'
	mov ah,02h
	int 21h

	mov al,cl
	aam
	add ax,3030h
	mov bx,ax
	call d
	
	mov ah,4ch
	int 21h

d proc

	mov dl,bh
	mov ah,02h
	int 21h

	mov dl,bl
	mov ah,02h
	int 21h
	ret


d endp

code ends
end start
	
	
	
