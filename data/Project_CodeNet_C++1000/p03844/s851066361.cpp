#include <iostream>

using namespace std;

int main()
{
    int a, b, sum;
    char ope;
    cin >> a >> ope >> b;

    if (ope == '+')
    {
        sum = a + b;
    }
    else
    {
        sum = a - b;
    }

    cout << sum << endl;

    return 0;
}