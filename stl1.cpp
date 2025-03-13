/*/ Використовуючи механізм шаблонного успадкування створіть ієрархію класів.
 *Базовий клас під назвою base має наступні змінні-члени:
 *1) T1 value1;// деяке значення.
 *2) T2 value2; // деяке значення.
 *Нащадок під назвою child містить додаткові змінні-члени:
 *3) T3 value3.
 *4) T4 value4.
 *Нащадок під назвою child2 додає такі змінні-члени:
 *5) T5 value5. 6) T6 value6.
 *Кожен клас має необхідний набір конструкторів, деструкторів, функцій-членів для роботи зі структурою класу.
 *В main протестувати роботу класу.
/*/

#include <iostream>
#include <string>
using namespace std;
template <typename T1, typename T2>
class base{
public:
    T1 value1;
    T2 value2;

    base(T1 v1, T2 v2) : value1(v1), value2(v2) {}
    virtual ~base() {}

    void virtual display() const {
        cout << "Base values: " << value1 << ", " << value2 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2> {
public:
    T3 value3;
    T4 value4;

    child(T1 v1, T2 v2, T3 v3, T4 v4) : base<T1, T2>(v1, v2), value3(v3), value4(v4) {}
    ~child() override {}

    void display() const override{
        base<T1, T2>::display();
        cout << "Child values: " << value3 << ", " << value4 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4> {
public:
    T5 value5;
    T6 value6;

    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}
    ~child2() override {}

    void display() const override{
        child<T1, T2, T3, T4>::display();
        cout << "Child2 values: " << value5 << ", " << value6 << endl;
    }
};

int main() {
    child2<int, double, char, string, bool, float> pro(1, 2.5, 'a', "hello", true,  3.14f);
    pro.display();
    return 0;
}