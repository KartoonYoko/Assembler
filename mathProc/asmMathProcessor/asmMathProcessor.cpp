

#include <iostream>

int main()
{
    /*
        Task #16

        Найти площадь окружности.

        c = 2 * r * PI

        s= PI * r^2


    */

    setlocale(LC_ALL, "Rus");

    float pi = 3.14;
    float c; // длина окружности
    float result = 0;
    float two = 2;

    std::cout << "Введите длину окружности c = ";
    std::cin >> c;



    //fmul st(2), st(4)

    __asm {
        fld [c]; st(0)
        fld [pi]
        fld [two]

        fdiv st(0), st(1)
        fdiv st(0), st(2)
        fmul st(0), st(0)
        fmul st(0), st(1)


        fst [result]

    }

    std::cout << std::endl << "Ответ = " << result;
}

