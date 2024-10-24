; Masking example

;INCLUDE Irvine32.inc
;
;.data
;	myArray	BYTE	50 DUP(0)
;.code
;main PROC
;	mov		ecx, LENGTHOF myArray
;	mov		esi, OFFSET myArray
;
;L1:
;	or		BYTE PTR [esi], 00100000b
;	inc		esi
;	loop	L1
;
;	exit
; main ENDP
; END main


; Cmp and flags


;INCLUDE Irvine32.inc
;
;.data
;
;.code
;main PROC
;	xor		eax, 1
;	mov		ax, 5
;	cmp		ax, 10
;
;	
;	mov		ax, 11
;	sub		ax, ax
;	sub		ax, 12
;
;	mov		al, 01010101b
;	and		al, 00000000b
;
;	mov		al, 01010101b
;	or		al, 11111111b
;
;	exit
;main ENDP
;END main
;


;INCLUDE Irvine32.inc
;
;.data
;	equalMsg	BYTE	"Its Equal", 0
;	notEqualMsg	BYTE	"Its not Equal", 0
;	endMsg		BYTE	"End Program", 0
;
;.code
;main PROC
;	mov		eax, 6
;	cmp		eax, 5
;	je		itsEqual
;	mov		edx, OFFSET notEqualMsg
;	call	WriteString
;	call    Crlf
;
;	jmp		endProgram
;
;itsEqual:
;	mov		edx, OFFSET equalMsg
;	call	WriteString
;	call    Crlf
;
;endProgram:
;	mov		edx, OFFSET endMsg
;	call	WriteString
;
;	exit
;main ENDP
;END main



; INCLUDE Irvine32.inc
;
; .data
;
;
; .code
; main PROC
;	mov		al, +127
;	cmp		al, -128
;	ja		IsAbove
;	nop
;	nop
;	jg		IsGreater
;
;IsAbove:
;	nop
;	nop
;
;IsGreater:
;	nop
;	nop
;
;	exit
; main ENDP
; END main


; INCLUDE Irvine32.inc
;
; .data
;
; .code
; main PROC
;	mov		edx, -1
;	cmp		edx, 0
;	jnl		L5
;	nop
;	nop
;	jnle	L5
;	nop
;	nop
;	jl		L1
;	nop 
;	nop
;
;L5:
;	nop
;	nop
;
;L1:
;	nop
;	nop
;
;	exit
; main ENDP
; END main


; INCLUDE Irvine32.inc
;
;.data
;
;.code
; main PROC
;	mov		edx, -1
;	cmp		edx, 0
;	jnl		L5
;	nop
;	nop
;	jnle	L5
;	nop
;	nop
;	jl		L1
;	nop
;	nop
;
; L5:
;	nop
;	nop
;
; L1:
;	nop
;	nop
;
;	exit
; main ENDP
; END main



; test for bits
; crucial for hardware devices
; INCLUDE Irvine32.inc
;
;	status = 01110101b
;.data
;
;.code
; main PROC
;	mov		al, status
;	test	al, 00100000b
;	jnz		DeviceOffline
;	nop 
;	nop
;
;DeviceOffline:
;	nop
;	nop
;
;	exit
; main ENDP
; END main


; Loop conditionals

;include irvine32.inc
;
;.data
;	myArray		SWORD	-3,-6,-1,-10,10,30,40,4
;	sentinel	SWORD	0
;
;.code
;main PROC
;	mov		esi, OFFSET		myArray
;	mov		ecx, LENGTHOF	myArray
;
;L1: 
;	test	WORD PTR [esi], 8000h
;	pushfd	
;	add		esi, TYPE myArray
;	popfd 
;	loopnz	L1
;	jnz		quit
;	sub		esi, TYPE myArray
;	nop
;	nop
;
;quit:
;	exit
;		 
;main ENDP
;END main
;


; Lets do example program from 6.2