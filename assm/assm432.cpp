

#include <iostream>

int main()
{
    
    // изменим немного формулу на p(x) = A2 * x^2 + A1 * x;
    // A1 = 1; A2 = 2; A3 = 3;


    short x = 1;
    short a1 = 1;
    short a2 = 2;

    __asm {

        ; начало процедуры
    proc_p:

        

        ret
         ; конец процедуры


    ; начало процедуры возведения в степень (возводит si в степень, которая хранится в cx)
    power_p:
        mov di, si
    pow:
        imul di, si
        loop pow       
        ; конец процедуры возведения в степень


    mov ax, x
    
    ; здесь можно реализовать ввод по одному значению и записывать его в стек
    mov bx, a1
    mov dx, a2
    push bx
    push dx

    }
}

