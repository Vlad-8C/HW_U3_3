//+++++++++++++++++++++++++++++++++++++++++++++Задача 1. Калькулятор двух чисел+++++++++++++++++++++++++++++++++++++++++//

#include <iostream>

class Calculator
{
private:
    double num1{};
    double num2{};
public:
    Calculator() = default;
    Calculator(double n1, double n2) : num1(n1), num2(n2) {};
    double const add(Calculator obj) const { return obj.num1 + obj.num2; }; // метод должен возвращать результат сложения num1 и num2
    double const multiply(Calculator obj) const { return obj.num1 * obj.num2; }; // метод должен возвращать результат перемножения num1 и num2
    double const subtract_1_2(Calculator obj) const { return obj.num1 - obj.num2; }; // метод должен возвращать результат вычитания num2 из num1
    double const subtract_2_1(Calculator obj) const { return obj.num2 - obj.num1; }; // метод должен возвращать результат вычитания num1 из num2
    double const divide_1_2(Calculator obj) const { return (obj.num2 == 0) ? 0 : obj.num1 / obj.num2; }; // метод должен возвращать результат деления num1 на num2
    double const divide_2_1(Calculator obj) const { return (obj.num1 == 0) ? 0 : obj.num2 / obj.num1; }; // метод должен возвращать результат деления num2 на num1
    bool set_num1(double num1) {
        if (num1 != 0) { this->num1 = num1; return true; }
        else
        {
            std::cout << "Incorrect write"<<std::endl;
            return false;
        }
    } // метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
    bool set_num2(double num2) {
        if (num2 != 0) { this->num2 = num2; return true; }
        {
            std::cout << "Incorrect write"<<std::endl;
            return false;
        }
    } // метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
    friend std::ostream& operator << (std::ostream& os, const Calculator& obj)
    {
        os << obj.num1 << '\n' << obj.num2 << std::endl; return os; 
    }
    // ~Calculator() { std::cout << "Calculator delet \n"; }

};

int main()
{
    Calculator var1{};
    //Calculator var1{ n1, n2 };
    double n1{}, n2{};
    while (true)
    {
        std::cout << "\nTo finish press \"ctrl+c\"" << std::endl;
        do
        {
            std::cout << "Write num1: "; std::cin >> n1;
        } while (!var1.set_num1(n1));

        do
        {
            std::cout << "Write num2: "; std::cin >> n2;
        } while (!var1.set_num2(n2));

        //std::cout << var1;

        std::cout << "num1 + num2 = " << var1.add(var1) << std::endl;
        std::cout << "num1 - num2 = " << var1.subtract_1_2(var1) << std::endl;
        std::cout << "num2 - num1 = " << var1.subtract_2_1(var1) << std::endl;
        std::cout << "num1 * num2 = " << var1.multiply(var1) << std::endl;
        std::cout << "num1 / num2 = " << var1.divide_1_2(var1) << std::endl;
        std::cout << "num2 / num1 = " << var1.divide_2_1(var1) << std::endl;
    }

    return EXIT_SUCCESS;
}

