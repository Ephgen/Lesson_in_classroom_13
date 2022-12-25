

#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void viewArr(int* arr, int* size)
{
    for (int i = 0; i < *size; i++) {
        cout << *(arr + i) << " ";
    }
}

int* createArr(int& size)
{
    cout << " Введите размерр массива\n";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % ((10 - 1) + 1);
    }
    return arr;
}

int* returnArr(int* arr,int& size)
{
    int sizeNEW = size + 1;
    int dobav;
    int* arrNEW = new int[sizeNEW];
    bool variant = true;

    cout << endl << " Введите число, которое надо добавить: ";
    cin >> dobav;
    while (dobav != 99)
    {
        if (variant)
        {
            sizeNEW = size + 1;
            arrNEW = new int[sizeNEW];
            for (int i = 0; i < size; i++)
                *(arrNEW + i) = *(arr + i);
            *(arrNEW + size) = dobav;
            variant = false;                
        }
        else
        {
            size = sizeNEW + 1;
            arr = new int[size];
            for (int i = 0; i < sizeNEW; i++)
                *(arr + i) = *(arrNEW + i);
            *(arr + sizeNEW) = dobav;
            variant = true;
        }
        cout << " Введите число, которое надо добавить: ";
        cin >> dobav;
    }
    if (variant)
        return arr;
    else
        size = sizeNEW;
    return arrNEW;        
}

int* delElement(int* arr, int& size)
{
    int sizeNEW = size;
    int udal;
    int* arrNEW = new int[sizeNEW];
    bool variant = true;
    cout << endl << " Введите число, которое надо убрать: ";
    cin >> udal;
    while (udal != 99)
    {
        int n = 0;
        if (variant)            
        {                      
            for (int i = 0; i < size; i++) {
                if (udal == *(arr + i))
                    n++;                
            }
            if (n == 0)
                cout << " нет такого числа\n";

            sizeNEW = size - n;
            arrNEW = new int[sizeNEW];

            for (int i = 0, j = 0; i < size; i++)
                if (udal != *(arr + i))
                    *(arrNEW + j++) = *(arr + i);                                                  
            variant = false;      
            viewArr(arrNEW, &sizeNEW);
        }        

        else
        {          
            for (int i = 0; i < sizeNEW; i++) {
                if (udal == *(arrNEW + i))
                    n++;               
            }
            if (n == 0)
                cout << " нет такого числа\n";

            size = sizeNEW - n;
            arr = new int[size];

            for (int i = 0, j = 0; i < sizeNEW; i++)
                if (udal != *(arrNEW + i))
                    *(arr + j++) = *(arrNEW + i);


            variant = true;
            viewArr(arr, &size);
        }        
        cout << endl << " Введите число, которое надо убрать: ";
            cin >> udal;
    }
    if (variant)
        return arr;
    else {
        size = sizeNEW;
        return arrNEW;
    }
}

int n = 15;
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    /* int sizeA;
     int* arrA = createArr(sizeA);
     viewArr(arrA, &sizeA);*/

     /* int sizeA;
      int* arrA = createArr(sizeA);
      viewArr(arrA, &sizeA);
      arrA = returnArr(arrA, sizeA);
      viewArr(arrA, &sizeA);*/

      /*int sizeA;
      int* arrA = createArr(sizeA);
      viewArr(arrA, &sizeA);
      arrA = delElement(arrA, sizeA);
      viewArr(arrA, &sizeA);*/

    //int len;
    //len = strlen;  // функция определяет длину строки
    //cout << len;

    /*char word[50];
    cin.getline(word, 50);
    int i = 0;
    while (*(word + i) != '\0')
    {
        i++;
    }
    cout << " Занято - " << i << endl;
    cout << " Свободно - " << 50 - i;*/

    //Многомерные динимические массивы
    int m1 = 5;
    int m2 = 2;
    int m3 = 3;
    /*int** A = new int* [m1];
    for (int i = 0; i < m1; i++) {
        A[i] = new int[m2];
    }
    for (int i = 0; i < m1; i++) {
        delete[] A[i];
    }
    delete[] A;*/
    int** pArr = new int* [m1];
    for (int i = 0; i < m1; i++) {
        pArr[i] = new int[m2];
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m2; j++) {
            pArr[i][j] = rand() % ((10 - 1) + 1);
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << pArr[i][j] << " ";
        }
        cout << endl;
    }
}

