#include "myarrfunc.h"
#include <stdio.h>
#include <wchar.h>

void print_menu(void){
    wprintf(L"\n");
    wprintf(L"a Задать размер массива\n");
    wprintf(L"b Заполнить массив\n");
    wprintf(L"c Представление массива (значения, адреса)\n");
    wprintf(L"d last_positive_index - индекс последнего положительного элемента\n");
    wprintf(L"e count_between_equal - количество элементов между двумя равными значениями\n");
    wprintf(L"f count_below_average - количество элементов ниже среднего значения\n");
    wprintf(L"g Выход\n");
    wprintf(L"Выберите пункт: ");
    fflush(stdout);
}

int last_positive_index(double *arrptr, size_t n){
    double *p;
    double *end = arrptr + n;
    int result = -1;

    for (p = arrptr; p < end; p++){
        if (*p > 0)
            result = (int)(p - arrptr);
    }
    return result;
}

int count_between_equal(double *arrptr, size_t n){
    double *p;
    double *q;
    double *end = arrptr + n;

    for (p = arrptr; p < end; p++){
        for (q = p + 1; q < end; q++){
            if (*p == *q)
                return (int)(q - p - 1);
        }
    }
    return -1;
}

int count_below_average(double *arrptr, size_t n){
    double *p;
    double *end = arrptr + n;
    double sum = 0;
    double average;
    int count = 0;

    if (n == 0)
        return -1;
    for (p = arrptr; p < end; p++)
        sum += *p;
    average = sum / n;
    for (p = arrptr; p < end; p++){
        if (*p < average)
            count++;
    }
    return count;
}