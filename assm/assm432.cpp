

#include <iostream>

int main()
{
    
    // изменим немного формулу на p(x) = A2 * x^2 + A1 * x;
    // A1 = 1; A2 = 2; A3 = 3;


    short x = 1;
    short a1 = 1;
    short a2 = 2;
    short result = 0;

    __asm {

        ; начало процедуры (AX (хранит x), BX ( для получения данных из стека), CX (степень), DX (РЕЗУЛЬТАТ), SI)
    proc_p:
        mov cx, 2; степень
        mov si, ax; переносим x в si для возведения в степень
        call power_p
        
        pop bx
        imul si, bx
        mov dx, 0
        add dx, si; 

        pop bx
        imul ax, bx

        add dx, ax; результат в DX
        
        

        ret
         ; конец процедуры


    ; начало процедуры возведения в степень (возводит si в степень, которая хранится в cx)
    power_p:
        mov di, si
    pow:
        imul di, si
        loop pow    
        ret
        ; конец процедуры возведения в степень


    mov ax, x
    
    ; здесь можно реализовать ввод по одному значению и записывать его в стек
    mov bx, a1
    mov dx, a2
    push dx
    push bx
       
    mov di, 0; di будет хранить ответ всей задачи
    call proc_p
    add di, dx
    
    ; повторная запись в стек
    mov bx, a1
    mov dx, a2
    push dx
    push bx


    add ax, -1

    call proc_p
    add di, dx

    mov result, di; ОТВЕТ


    }
}

