#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ll x, y ;
    string a, b ;
    cin >> a >> b ;
    x=a.size();
    y=b.size();
    ll flag=-1;
    if(x<y)
        flag=0;
    else if(x>y)
        flag=1;
    else
    {
        ll i, j ;
        for(i=0; i<x; i++)
        {
            if(a[i]>b[i])
            {
                flag=1;
                break;
            }
            else if(a[i]<b[i])
            {
                flag=0;
                break;
            }
        }
    }
    if(flag==-1)
        cout << "EQUAL";
    else if(flag==1)
        cout << "GREATER";
    else
        cout << "LESS";
    return 0;
}