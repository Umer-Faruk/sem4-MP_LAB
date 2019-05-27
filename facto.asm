assume cs:code,ds:data,ss:stackseg
data segment
	n db 05h
	res db ?
data ends
stackseg segment
	stack dw 40 dup(?)
	stack_top label word
stackseg ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov ax,stackseg
	mov ss,ax

	lea sp,stack_top

	mov al,n
	mov ah,00
	call fact
	
	

	mov ah,4ch
	

        int 21h
 fact proc
	cmp al,00
	je cal
	push ax
	dec al
	call fact
	pop ax
	mul res
	mov res,al
	ret
cal:
	mov res,01h
	ret
	fact endp
code ends
end start
