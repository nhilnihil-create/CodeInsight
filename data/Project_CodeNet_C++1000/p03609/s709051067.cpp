#include<iostream>
 using namespace std;

int main ()
{
    int c;
    int x,t;
    cin >> x;
    cin >> t;
    if (x>t)
    {
        c = x-t;
        cout << c << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}
