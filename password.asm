
assume cs:code,ds:data
;disp macro mes
;lea dx,mes
;int 21h
;end m

data segment
pas1 db '123'
len1 db len1-pas1
pas2 db 10 dup(?)
len2 db ?

msg1 db 0dh,0ah,"password math$"
msg2 db 0dh,0ah,"password not match$"
msg3 db 0dh,0ah,"3 chansess are over$"
msg4 db 0dh,0ah,"enter the password$"

data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	mov bl,0
	
rpt:	call readpass
	call match
	inc bl
	cmp bl,3
	jb rpt
	

	lea dx,msg3 ;3 attempts are over
	mov ah,09h
	int 21h

	mov ah,4ch
	int 21h



readpass proc near


	
	lea dx,msg4 ;reading password
	mov ah,09h
	int 21h

	mov bh,00
	lea si,pas2

agin:	mov ah,8 	;getting input from keyboar
	int 21h	
	
	cmp al,0dh	;chaking enter is press are not
	je next
	
	mov [si],al
	inc si
	inc bh		;inc menting bh to find length of password

	mov dl,'*'	;replacing password with "*"
	mov ah,2
	int 21h


	jmp agin	;running the loop until press enter kay


next:	mov len2,bh	;if we prss enter it move the length of pass to len2
				;return for password maching
	ret

readpass endp



match proc near
	mov cl,len1
	cmp cl,len2
	je matchstr	
	jmp notmatch

matchstr:	
		lea si,pas1	;do same as palindrom check
		lea di,pas2
	
		cld
		mov ch,0

		repe cmpsb
		jnz notmatch


		
		lea dx,msg1
		mov ah,09h
		int 21h

		mov ah,4ch
		 int 21h

notmatch:	
		lea dx,msg2
		mov ah,09h
		int 21h
		ret
match endp
code ends
end start	
	









