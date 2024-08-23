    .intel_syntax noprefix

    .text

    .global sum
    .global diff

    # int sum(int a, int b)
    sum:
        push rbp
        mov rbp,rsp
        mov rax,rdi   # a
        add raz,rsi   # b

        pop rbp
        ret

    diff:
        push rbp
        mov rbp,rsppush rbx

        mov rax,[rdi]   # &a 
        mov rbx,[rsi]   # &b
        sub rax,rbx     # b

        pop rbx
        pop rbp
        ret