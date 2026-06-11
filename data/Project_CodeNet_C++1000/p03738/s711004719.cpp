#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a,b;
    cin>>a>>b;
    if( a.length()> b.length())
        cout<<"GREATER";
    if( a.length()<b.length())
        cout<<"LESS";
    if( a.length()== b.length())
    {
        if( a> b)
        {
            cout<<"GREATER";
        }
        if( a<b)
        {
            cout<<"LESS";
        }
        if( a== b)
            cout<<"EQUAL";
    }
}