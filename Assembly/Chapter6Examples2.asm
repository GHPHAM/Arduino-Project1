; Block - Structure IF Statements
; short - circuit evaluation
; for && - if the first expression is false, the second is not evaluated
; for || - if the first expression is true, the second does not need to be evaluated

; if varA < varB && varA < varC

INCLUDE Irvine32.inc

.data
TRUE = 1
FALSE = 0
varA DWORD 7
varB DWORD 8
varC DWORD 6
result DWORD 0

.code
main PROC
	mov		eax, varA
	cmp		eax, varB
	jb		L1
	mov		ebx, FALSE
	jmp		exitProgram
L1:
	cmp		eax, varC
	jb		L2

L2:
	mov		ebx, TRUE

exitProgram:
	exit
main ENDP
END main


; if varA > varB || varB > varC

;INCLUDE Irvine32.inc
;
;.data
;TRUE = 1
;FALSE = 0
;varA DWORD 7
;varB DWORD 8
;varC DWORD 6
;result DWORD 0
;
;.code
;main PROC
;	mov		eax, varA
;	cmp		eax, varB
;	jg		L1
;	mov		eax, varB
;	cmp		eax, varC
;	jg		L2
;L1:
;	mov 	ebx, FALSE
;	jmp		exitProgram
;
;L2:
;	mov		ebx, TRUE
;
;exitProgram:
;
;	nop
;	nop
;
;	exit
; main ENDP
; END main


; while loop
; while ( val1 < val2)
; { val++; val--; }

;INCLUDE Irvine32.inc
;
;.data
;val1		BYTE	0
;val2		BYTE	10
;
;.code
;main PROC
;	movzx	eax, val1
;BeginWhile:
;	cmp		al, val2
;	jg		ExitWhile
;	inc		al
;	dec		val2
;	jmp		BeginWhile
;
;ExitWhile:
;	nop
;	nop
;
; exit
; main ENDP
; END main


; if statement nested in a loop
;
; int array[] = {10,60,20,33,72,89,45,65,72,18};
; int sample = 50;
; int ArraySize = sizeof array / sizeof sample;
; int index = 0;
; int sum = 0;
; while (index < ArraySize)
; {
; 	if (array[index] > sample)
; 	{
; 		sum += array[index];
; 	}
; 	index++;
; }

; INCLUDE Irvine32.inc
;
; .data
;sum		DWORD	0
;sample	DWORD	50
;myArray	DWORD	10,60,20,33,72,89,45,65,72,18
;ArraySize = ($ - Array) / TYPE myArray
;
; .code
; main PROC
;	 mov	eax, 0				;sum
;	 mov	edx, sample
;	 mov	esi, 0				;index
;	 mov	ecx, ArraySize 
;L1:
;	 cmp	esi, ecx			;if myArray[esi] > edx
;	 jl		L2 
;	 jmp	L5
;L2:
;	 cmp	myArray[esi * 4], edx	;if myArray[esi] > edx
;	 jg		L3
;	 jmp	L4
;L3:
;	 add	eax, myArray[esi * 4]
;L4:
;	 inc	esi
;	 jmp    L1
;L5:
;	 mov	sum, eax
;
;
; exit
; main ENDP
; END main

