// lr_6_2500.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

int return_max(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int func_2(int low, int upper) {
    double value;
    cout << "Введите число: ";
    cin >> value;
    if (value == int(value)) {
        if (value >= low && value <= upper) {
            return value;
        }
        else {
            return -10;
        }
    }
    else {
        return 0;
    }
}

void menu() {
    bool work = true;
    int low = -1, upper = -1, value = -1;
    while (work){
        cout << "1) Ввод верхнего предела" << endl;
        cout << "2) Ввод нижнего предела" << endl;
        cout << "3) Ввести число" << endl;
        cout << "4) Выход" << endl;
        int choice;
        do {
            cin >> choice;
        } while (choice < 1 || choice > 4);

        switch (choice) {
        case 1:
            cout << "Введите верхний предел: ";
            cin >> upper;
            break;
        case 2:
            cout << "Введите нижний предел: ";
            cin >> low;
            break;
        case 3:
            cout << "Введите число: ";
            cin >> value;
            break;
        case 4: work = false; break;
        }

        if (low != -1 && upper != -1 && value != -1) {
            int result = func_2(low, upper);
            if (result == 0) work = false;
            if (result == -10) continue;
        }

    }
}


void sort_inserts() {
    srand(time(NULL));
    int temp;
    int n = 10;
    int* arr = new int[n];
    cout << "Начальные данные" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
    cout << "Отсортированные данные" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}


int main()
{
    setlocale(LC_ALL, "ru");
    //cout << return_max(3, 123, 6) << endl;
    //menu();
    sort_inserts();
}

