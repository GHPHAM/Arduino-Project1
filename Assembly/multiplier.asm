; Lab2 - 3.asm
; Huy Pham
; 9 / 11 / 2024

.386
.model  flat, stdcall
.stack  4096
ExitProcess PROTO, dwExitCode:DWORD

.data

original dword 00000000h ;stores the original

.code

; Multiplier in EBX
; Multiplicant in EAX
; Multiplicant buffer in ECX
; sum to add back in EDX
BitwiseMultiply PROC
    cmp EBX, 0h            ; Return if multiplying by zero
    JE mulByZero;

    mov [original], EAX    ; Store the original value
    mov EDX, 0             ; Initialize sum to 0
    mov ECX, EBX           ; Copy EBX to ECX to preserve EBX
    mov EBX, [original]    ; Set EBX as the original multiplicand

loop1:
    cmp ECX, 0h            ; Check if ECX is zero
    JE return              

    test ECX, 1            ; Test if the least significant bit of ECX is 1
    JZ skip_add            ; If zero, skip the addition

    add EDX, EBX           ; Add the multiplicand to the sum if the bit is set

skip_add:
    shl EBX, 1             ; Shift multiplicand left (multiply by 2)
    shr ECX, 1             ; Shift ECX right (move to the next bit)

    jmp loop1              ; Repeat the loop

mulByZero:
    mov EDX, 0h            
    jmp return

return:
    mov EAX, EDX           ; Move the final result to EAX
    ret
BitwiseMultiply ENDP



main    PROC
    mov EAX, 3h
    mov EBX, 7h
    call BitWiseMultiply


    INVOKE ExitProcess, 0
main    ENDP
END main
