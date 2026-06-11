# include <iostream>
using namespace std;

int main()
{
    char op;
    int num1, num2;

    cin >> num1 >> op >> num2;

    if (op == '+')
        cout << num1+num2;

    if (op == '-')
        cout << num1-num2;
}