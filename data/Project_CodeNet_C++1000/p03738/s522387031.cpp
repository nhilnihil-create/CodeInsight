#include<iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
#define endl "\n"
#define SRK ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EPS 1e-6
typedef long long ll;
using namespace std;


    int main()
{
    SRK;
    int i,temp = 0;
    string a,b;
    cin >> a >> b;
    if (a.length() == b.length())
    {
        for (i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            else if ((a[i]-'0') > (b[i]-'0'))
            {
                temp = 1;
                cout << "GREATER\n";
                break;
            }
            else
            {
                temp = 1;
                cout << "LESS\n";
                break;
            }
        }
    }
    else
    {
        if (a.length() > b.length())
        {
            temp = 1;
            cout << "GREATER\n";
        }
        else
        {
            temp = 1;
            cout << "LESS\n";
        }
    }
    if (temp == 0)
    {
        cout << "EQUAL\n";
    }


}

