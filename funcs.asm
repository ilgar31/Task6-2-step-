section .data
    two dd 2
    three dd 3
    five dd 5
    nineteen dd 19

section .text
global _f1, _f2, _f3

_f1:
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fld qword [ebp + 8]
    fld1
    faddp                  ; x + 1
    fild dword [two]
    fmulp                  ; 2 * (x + 1)
    fld1
    fdivrp                 ; 0.5/(x+1)
    fld1
    faddp                  ; 0.5/(x+1) + 1
    fild dword [three]
    fmulp                  ; 3 * (0.5/(x+1) + 1)
    
    leave
    ret

_f2:
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fld qword [ebp + 8]
    fild dword [five]
    fmulp                  ; 5 * x
    fild dword [nineteen]
    fsubp                  ; 5*x - 19
    fild dword [two]
    fdivp                  ; 2.5x − 9.5
    
    leave
    ret

_f3:
    push ebp
    mov ebp, esp
    sub esp, 24
    
    finit
    fild dword [five]
    fld qword [ebp + 8]
    fdivp                  ; 5 / x
    
    leave
    ret
