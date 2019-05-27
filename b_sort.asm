assume cs:code,ds:data
data segment
arr db 10,20,15,12,6
x dw arr-x


data ends
code segment
start:
	mov ax,data
	mov ds,ax

	mov bx,x
	dec bx
n_p:
	mov cx,bx
	mov ah,00
	lea si,arr
n_c:
	mov al,[si]
	cmp al,[si +1]
	jle do_nothing
	xchg al,[si]
	mov [si],al
	mov ah,1
do_nothing:
		inc si
		loop n_c
		cmp ah,00
		je finesh
		dec bx
		jnz n_p
finesh:
	mov ah,4ch
	int 21h






code ends
end start
