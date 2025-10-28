// Лабораторная работа № 2 Вариант 1

#include <iostream>

using namespace std;

class Myclass {
   private:
      int x, y; 

   public:
      Myclass(int a, int b) : x(a), y(b) {}
      // Дружественная функции для перегрузки 
      friend int operator-(const Myclass& obj1, const Myclass& obj2);

      void print() {
         cout << "x = " << x << ", y = " << y << endl;
      }

};

// Реализация перегруженного оператора -
int operator-(const Myclass& obj1, const Myclass& obj2){
   // Проверка доступа к private
   return obj1.x * obj1.y * obj2.x * obj2.y;
}

int main() {
   // Создаем два объекта
   Myclass obj1(2, 3);
   Myclass obj2(4, 5);

   cout << "Объект 1: ";
   obj1.print();

   cout << "Объект 2: ";
   obj2.print();

   int result = obj1 - obj2;


   cout << "Результат obj1 - obj2 = " << result << endl;
   cout << "Проверка 2 * 3 * 4 * 5 = " << endl;

   return 0;
}