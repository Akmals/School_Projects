
include Irvine32.inc
.data

;request input from user 
;lists variables and keywords
input BYTE "Please enter any number: ", 0
output BYTE "Primes found until the given number:", 0
next BYTE "Press any key to continue...", 0
num DWORD ?

.code
main proc

;reads number given by user
	mov edx, OFFSET input	
	call writeString					
	call readDec						
	mov num, eax						
	mov edx, OFFSET output		
	call writeString					
	call crlf							
	
; print all prime numbers up to num
	mov ecx, 2

;loop to check for prime numbers
WHILE1:
	cmp ecx, num
	ja ENDWHILE01			
	call isPrime			
	
	cmp ebx, 1
	jne ENDIF01				
	mov eax, ecx		
	call writeDec			
	mov al, ' '				
	call writeChar		

ENDIF1:
	inc ecx					
	jmp 

; prints primes larger than 1
ENDWHILE01:
	mov edx, OFFSET next	
	call writeString			
	call readChar					
	call crlf						
	exit

main endp

;is prime procedure
isPrime proc

 ; 1 = prime, 0 = not prime
	mov ebx, 1    
	mov esi, 2	
	
WHILE2:
	cmp esi, ecx
	jae ENDWHILE02			
	mov eax, ecx			
	xor edx, edx			
	div esi					

	cmp edx, 0
	je ENDWHILE02			
	inc esi					
	jmp WHILE02		
	
ENDWHILE2:
	cmp edx, 0				
	jne ENDIF02				
	mov ebx, 0				
ENDIF2:
					
isPrime endp
main endp
end main

