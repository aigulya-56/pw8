#include "myarrfunc.h"
#include <locale.h>
#include <wchar.h>

/*
a Задать размер массива
b Заполнить массив
c Представление массива (значения, адреса)
d last_positive_index - индекс последнего положительного элемента
e count_between_equal - количество элементов между двумя равными значениями
f count_below_average - количество элементов ниже среднего значения
g Выход
Выберите пункт: _
*/

static void clear_input(void){
    wint_t c;

    while ((c = getwchar()) != L'\n' && c != WEOF);
}

int main(void){
    wint_t a;
    int i;
    int result;
    int array_length = 0;
    int is_filled = 0;
    double array[9999] = {0};

    setlocale(LC_ALL, "");
    print_menu();

    while (((a = getwchar()) != WEOF) && (a != L'g')){
        switch(a){
            case L'\n':
            case L' ':
            break;

            case L'a':
            wprintf(L"Введите размер массива (1-9999): ");
            if (wscanf(L"%d", &array_length) != 1 || array_length < 1 || array_length > 9999){
                wprintf(L"Некорректный размер массива\n");
                array_length = 0;
                clear_input();
            }
            is_filled = 0;
            print_menu();
            break;

            case L'b':
            if (array_length == 0){
                wprintf(L"Вы не задали размер массива!\n");
            }
            else{
                wprintf(L"Введите элементы массива (всего %d): ", array_length);
                is_filled = 1;
                for (i = 0; i < array_length; i++){
                    if (wscanf(L"%lf", array + i) != 1){
                        wprintf(L"Некорректный ввод элемента\n");
                        is_filled = 0;
                        clear_input();
                        break;
                    }
                }
            }
            print_menu();
            break;

            case L'c':
            if (array_length == 0){
                wprintf(L"Вы не задали размер массива!\n");
            }
            else{
                wprintf(L"Элементы массива и их адреса:\n");
                for (i = 0; i < array_length; i++)
                    wprintf(L"array[%d] = %.2f, адрес %p\n", i, *(array + i), (void *)(array + i));
            }
            print_menu();
            break;

            case L'd':
            if (array_length == 0){
                wprintf(L"Вы не задали размер массива!\n");
            }
            else if (!is_filled){
                wprintf(L"Вы не заполнили массив!\n");
            }
            else{
                result = last_positive_index(array, array_length);
                if (result == -1)
                    wprintf(L"Положительных элементов в массиве нет\n");
                else
                    wprintf(L"Индекс последнего положительного элемента: %d\n", result);
            }
            print_menu();
            break;

            case L'e':
            if (array_length == 0){
                wprintf(L"Вы не задали размер массива!\n");
            }
            else if (!is_filled){
                wprintf(L"Вы не заполнили массив!\n");
            }
            else{
                result = count_between_equal(array, array_length);
                if (result == -1)
                    wprintf(L"В массиве нет двух равных значений\n");
                else
                    wprintf(L"Количество элементов между равными значениями: %d\n", result);
            }
            print_menu();
            break;

            case L'f':
            if (array_length == 0){
                wprintf(L"Вы не задали размер массива!\n");
            }
            else if (!is_filled){
                wprintf(L"Вы не заполнили массив!\n");
            }
            else{
                result = count_below_average(array, array_length);
                wprintf(L"Количество элементов ниже среднего значения: %d\n", result);
            }
            print_menu();
            break;

            default:
            wprintf(L"Нет такого пункта меню\n");
            clear_input();
            print_menu();
            break;
        }
    }
    wprintf(L"\n");
    return 0;
}