#include<iostream>
 using namespace std;

int main ()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int e,f,g;
    e = a+b;
    f = a+c;
    g = b+c;
    if (e<=f && e <= g)
    {
        cout << e << endl;
    }
    else if (f <= e && f <= g)
    {
        cout << f << endl;
    }
    else if (g <= e && g <= f)
    {
        cout << g << endl;
    }
    return 0;
}