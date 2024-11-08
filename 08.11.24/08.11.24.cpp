#include<iostream>
#include<time.h>
using namespace std;

template<class T >
class MyArray
{
    T* mas = nullptr;
    int size;
public:
    MyArray();
    void Output();
    ~MyArray();
    T operator[](int index);
    int GetSize()const
    {
        return size;
    }
    T* GetPtr()const
    {
        return mas;
    }
    void SetSize(int s)
    {
        size = s;
    }
    void SetPtr(T* ptr)
    {
        mas = ptr;
    }
};
template<class T>MyArray<T>::MyArray()
{
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % 100 * 1.2;
    }
}
template<class T>void MyArray<T>::Output()
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}
template<class T>MyArray<T>::~MyArray()
{
    if (mas != nullptr)
    {
        delete[] mas;
    }
}
template<class T>T MyArray<T>::operator[](int index)
{
    return mas[index];
}

class Point
{
    int x;
    int y;
public:
    Point() { x = y = 0; };
    Point(int _x, int _y) { x = _x; y = _y; };
    void Print() {
        cout << "X " << x << "\tY " << y << endl;
    }
    void Init() {
        cout << "Input x -";
        cin >> x;
        cout << "Input y -";
        cin >> y;
    }
    int getX() { return x; };
    int getY() { return y; };
    int setX(int _x) { x = _x; };
    int setY(int _y) { y = _y; };
    Point operator+(Point& obj) {
        Point temp;
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        return temp;
    };

    operator double() { return x + y; }
    operator Point() { return Point(x, y);}
};
ostream operator<<(ostream& os, Point& obj) {
    os << "X - " << obj.getX() << endl << "Y - " << obj.getY();
}

istream operator>>(istream& is, Point& obj) {
    int _x, _y;
    cout << "Input x - ";
    is >> _x;
    cout << "Input y - ";
    is >> _y;
}

int main()
{
    srand(time(0));
    MyArray<int> obj1;
    obj1.Output();

    MyArray<char> obj2;
    obj2.Output();

    MyArray<double>obj3;
    obj3.Output();

    MyArray<Point> obj4;


    system("pause");
}



