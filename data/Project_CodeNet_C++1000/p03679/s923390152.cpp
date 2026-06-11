#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >>c;
    int d;
    d = c-b;
    if(b >= c)
    {
        cout << "delicious" <<endl;
    }
    else if(d <= a)
    {
        cout << "safe" <<endl;
    }
    else
    {
        cout << "dangerous" <<endl;
    }
    return 0;
}
