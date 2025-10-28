#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {  

    double x, y; 

    cout << "Введите значение x: ";
    cin >> x;

    if (x <= 1 && x >= -1)
    {
        y = sqrt((2 * x + sin(fabs(3 * x))) / 3.56);
        cout << "Ваш ответ: " << setprecision(3) << setw(10) <<  y << endl;
    }
    else
    {
        cout << "Не существует" << endl;

    }
    
    return 0;
}