#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B;
    cin >> A;
    cin >> B;
    int d;
    d = A+B;

    if(A%3 == 0 || B%3 == 0 || d%3 == 0)
    {
        cout <<"Possible" <<endl;
    }
    else
    {
        cout << "Impossible" <<endl;
    }
    return 0;
}
