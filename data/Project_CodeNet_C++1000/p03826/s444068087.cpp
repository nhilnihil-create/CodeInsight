#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A,B,C,D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    int d,e;
    d = A*B;
    e = C*D;
    if(d>e)
    {
        cout << d <<endl;
    }
    else if (e>d)
    {
        cout << e <<endl;
    }
    else if(d == e)
    {
        cout <<d <<endl;
    }
    return 0;

}