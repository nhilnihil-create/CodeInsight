#include<iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < c)
        a = c;
    if(b > d)
        b = d;
    if(b - a > 0)
        cout << b - a;
    else
        cout << 0;
    return 0;
}