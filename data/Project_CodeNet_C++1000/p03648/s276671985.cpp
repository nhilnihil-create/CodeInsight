#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long

int main()
{
    ll k;
    while(cin >> k)
    {
        ll ro = k / 50;
        ll yu = k % 50;
        ll ty = ro - yu;
        cout << 50 << endl;
        for(int i = 0;i < 50;i++)
        {
            if(i < yu)
            cout <<  i + ty + 51;
            else
            cout << i + ty;
            if(i != 49)
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}

