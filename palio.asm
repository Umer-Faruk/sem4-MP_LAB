assume cs:code,ds:data
data segment
	str1 db "madam"
	n dw n-str1
	msg1 db "not a palindrome$"
	msg2 db "palindrome$"
	str2 db 5 dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
 	mov es,ax
	lea si,n
	dec si
	lea di,str2
	mov cx,n
 n1:
	mov al,[si]
	mov [di],al
	dec si
	inc di
	loop n1
	lea si, str1
	lea di,str2
 cld
 	mov cx,n
	repe cmpsb
	jnz not_good
	lea dx,msg2
	jmp disp
not_good:
	lea dx,msg1
disp:
 	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
	code ends
	end start
