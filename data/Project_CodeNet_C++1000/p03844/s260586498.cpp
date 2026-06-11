#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b;
    string s;
    cin>>a;
    cin>>s;
    cin>>b;
    if(s=="+")
    {
        cout<<(a+b);
    }
    else
    {
        cout<<(a-b);
    }
}
