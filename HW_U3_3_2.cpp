// HW_U3_3_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


class Counter
{
private:
public:
    double var{};
    //int one{ 1 };
public:
    Counter() : var{ 1 } {};
    Counter(double v) : var{ v } {};
    void set(double& num) { var = num; }
    void operator + (Counter& obj) const { ++ obj.var; }
    //void operator + (Counter obj) const { obj.var = obj.var + obj.one; }
    void operator - (Counter& obj) const { -- obj.var; }
    void operator = (Counter& obj) const { std::cout << obj; }

    friend std::ostream& operator << (std::ostream& os, const Counter& obj)
    {
        os << obj.var << std::endl; return os;
    }
};



int main()
{
    setlocale(LC_ALL, "Rus");
    std::string ansver{};
    Counter obj;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите y-да или n-нет: "; std::cin >> ansver;
    if (ansver=="y")
    {
        double num{};
        std::cout << "Введите начальное значение счетчика: "; std::cin >> num;
        obj.set(num);
    }
    
    char oper{};
    while (oper != 'x')
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): "; std::cin >> oper;
        if (oper == '+') obj + obj;
        if (oper == '-') obj - obj;
        if (oper == '=') obj = obj;
    }
    std::cout << "Bey bey"<<std::endl;

    return EXIT_SUCCESS;
}
