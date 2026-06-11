#include <bits/stdc++.h>

using namespace std;

int main() {
    /* code */
    int A, B, C, D, E;
    cin >> A;
    if (A<=1)
    {
        cout << 1 << endl;
        /* code */
    }else if (A<=3)
    {
        cout << 2 << endl;
        /* code */
    }else if (A<=7)
    {
        cout << 4 << endl;
        /* code */
    } else if (A<=15)
    {
        cout << 8 << endl;
        /* code */
    } else if (A<=31)
    {
        cout << 16 << endl;
        /* code */
    }else if (A<=63)
    {
        cout << 32 << endl;
        /* code */
    }else if (A<=100)
    {
        cout << 64 << endl;
        /* code */
    }
    return 0;
}