assume cs:code,ds:data
data segment
	res db ?
	cnt db 0ah
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov cl,cnt
	lea si,res
	mov ax,00h
	mov bx,01h
l1:
	add ax,bx
	mov [si],ax
	mov ax,bx
	mov bx,[si]
	inc si
	loop l1

	mov ah,4ch
	int 21h
code ends
end start
