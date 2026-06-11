#include <iostream>

using namespace std;

int main()
{
    int a, b, h, flag = 1;;
    cin >> a;
    if(a<1 || a>100) flag =0;
    cin >> b;
    if(b<1 || b>100) flag = 0;
    cin >> h;
    if(h<1 || h>100 || (h%2 != 0)) flag = 0;
    if(flag)
    {
        cout << (a+b)*h/2;
    }
    return 0;
}
