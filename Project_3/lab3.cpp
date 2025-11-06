// Лабораторная работа № 3 вариант 1

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class dynamicarray{
    protected:
        int size;
        T* data;
    public:
        dynamicarray(int n, T first, T step){
            size = n;
            data = new T[size];
            string res = "";
            if constexpr (is_arithmetic_v<T>){ // Проверка на тип данных (является ли числовым?)
                for (int i = 0; i < size; i++){
                data[i] = first + i * step;
            }
            }
            else{
                for (int i = 0; i < size; i++){
                    res += step;
                    data[i] = first + res;
            }
            }
            
        }

        ~dynamicarray(){
            delete[] data;
        }

        void print(){
            for (int i = 0; i < size; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    dynamicarray<float> array(10, 2.0, 1.3);
    array.print();
    dynamicarray<int> array1(10, 1, 2);
    array1.print();
    dynamicarray<string> array2(10, "a", "b");
    array2.print();
    dynamicarray<double> array3(10, 1.2131, 1.2323113);
    array3.print();
}