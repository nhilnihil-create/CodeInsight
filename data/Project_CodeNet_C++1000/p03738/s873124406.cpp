#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;
    string a,b;
    cin >> a >> b;
    int n1 = a.length();
    int n2 = b.length();

    if( n1 < n2)
    {
        cout << "LESS";
    }
    else if( n1 > n2)
    {
        cout << "GREATER";
    }
    else
    {
        if( a > b)
        {
            cout << "GREATER";
        }
        else if(a < b)
        {
            cout << "LESS";
        }
        else
        {
            cout << "EQUAL";
        }
    }
}
