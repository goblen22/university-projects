#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() { 
    char a;
    cout << "Введите любой символ: ";
    cin >> a;
    cout << "Символ: "<<  a << " ASCII: " << (int)a << " Шестнадцатеричный код: 0x" << hex << int(a) << dec << endl;
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Эта строка удаляет все символы из буфера до следующего \n

    string b;
    cout << "Введите строку из двух слов и 15 символов: ";
    getline(cin, b);
    while (b.length() < 15){
        cout << "Ввидите строку заново: " << endl;
        getline(cin, b); // ввод целой строки (включая пробелы)
    }
    size_t count = 0; // счетчик пробельных символов
    for (char c : b){
        if (isspace(c)) count++;
    }
    while (count < 1){
        cout << "Строка должна содержать минимум 2 слова! Введите снова: " << endl;
        getline(cin, b);
        count = 0;
        for (char c : b)
            if (isspace(c)) count++;
    }
    cout << "Строка: " << b << " Количество символов: " << b.length() << endl;
    cout << endl;

    int positiveInt, negativeInt;
    
    cout << "Введите положительное целое число: ";
    cin >> positiveInt;
    while (positiveInt <= 0) {
        cout << "Число должно быть положительным! Введите снова: ";
        cin >> positiveInt;
    }
    
    cout << "Введите отрицательное целое число: ";
    cin >> negativeInt;
    while (negativeInt >= 0) {
        cout << "Число должно быть отрицательным! Введите снова: ";
        cin >> negativeInt;
    }
    
    cout << "Десятичный вид:" << endl;
    cout << "  Положительное: " << positiveInt << endl;
    cout << "  Отрицательное: " << negativeInt << endl;
    
    cout << "Шестнадцатеричный вид:" << endl;
    cout << "  Положительное: 0x" << hex << positiveInt << dec << endl;
    cout << "  Отрицательное: 0x" << hex << negativeInt << dec << endl;
    
    cout << "Без коэффициента длины:" << endl;
    cout << "  " << positiveInt << " | " << negativeInt << endl;
    
    cout << "С левой позиции поля шириной 10:" << endl;
    cout << "  " << left << setw(10) << positiveInt << " | " << setw(10) << negativeInt << endl;
    
    cout << "С минимальной шириной поля 8:" << endl;
    cout << "  " << right << setw(8) << positiveInt << " | " << setw(8) << negativeInt << endl;
    
    cout << "Со смещением вправо (ширина 12):" << endl;
    cout << "  " << setw(12) << positiveInt << " | " << setw(12) << negativeInt << endl;
    cout << endl;

    double positiveFloat, negativeFloat;
    cout << "Введите положительное число с плавающей точкой: ";
    cin >> positiveFloat;
    while (positiveFloat <= 0) {
        cout << "Число должно быть положительным! Введите снова: ";
        cin >> positiveFloat;
    }

    cout << "Введите отрицательное число с плавающей точкой: ";
    cin >> negativeFloat;
    while (negativeFloat >= 0) {
        cout << "Число должно быть отрицательным! Введите снова: ";
        cin >> negativeFloat;
    }

    cout << fixed << setprecision(4); // Установка точности
    
    cout << "Десятичная форма (точность 4 знака):" << endl;
    cout << "  Положительное: " << positiveFloat << endl;
    cout << "  Отрицательное: " << negativeFloat << endl;
    
    cout << "Экспоненциальная форма (точность 3 знака):" << endl;
    cout << scientific << setprecision(3);
    cout << "  Положительное: " << positiveFloat << endl;
    cout << "  Отрицательное: " << negativeFloat << endl;
    
    cout << fixed; // Возврат к обычному формату
    cout << endl;
    
    // 5. 
    unsigned int unsignedNumber;
    
    cout << "Введите целое беззнаковое число: ";
    cin >> unsignedNumber;
    
    cout << "Десятичное целое без знака: " << unsignedNumber << endl;
    cout << "Восьмеричное целое без знака: 0" << oct << unsignedNumber << dec << endl;
    cout << "Шестнадцатеричное целое без знака: 0x" << hex << unsignedNumber << dec << endl;
    
}
