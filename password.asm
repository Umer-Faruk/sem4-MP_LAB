
assume cs:code,ds:data
data segment

	pas1 db '123'
	len1 db len1-pas1
	pas2 db 10 dup(?)
	len2 db ?

	m1 db 0dh,0ah,"enter the password$"
	m2 db 0dh,0ah,"3 attempts are oveer$"
	m3 db 0dh,0ah,"password machs$"
	m4 db 0dh,0ah,"password not maches$"
	

data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	
	mov bl,0
	
rpt:
	call readpass
	call matchpass
	inc bl
	cmp bl,3
	jb rpt
	
	lea dx,m2
	mov ah,09h
	int 21h

	mov ah,4ch
	int 21h

readpass proc 
		lea dx,m1
		mov ah,09h
		int 21h
	
		mov bh,00
		lea si,pas2		
	again:	mov ah,8
		int 21h
		
		cmp al,0dh
		je in_over
		;inc bh 
		mov [si],al
		inc si
                inc bh
	
		mov dl,'*'
		mov ah,02h
		int 21h
		jmp again
in_over:	
		mov len2,bh
		ret
		
		
	
	
readpass endp
		
			


matchpass proc
		
		mov cl,len1
		cmp cl,len2
		je startmatch
		jmp fail
		
	startmatch:
			lea si,pas1
			lea di,pas2
			
			cld
			mov ch,0
			repe cmpsb
			jnz fail
			
			lea dx,m3
			mov ah,09h
			int 21h
			
			mov ah,4ch
			int 21h




	fail:
		lea dx,m4
		mov ah,09h
		int 21h
		ret
			

matchpass endp
	





code ends
end start








