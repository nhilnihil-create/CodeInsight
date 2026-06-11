#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll b=0,s=0,n,c=0,a;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"Yes\n";
    }
    else if((a==1 || a==3 ||a==5 ||a==7 ||a==8 ||a==10 ||a== 12)  &&
    (b== 1|| b== 3||b== 5||b== 7||b== 8||b== 10||b== 12))
    {
        cout<<"Yes\n";
    }
    else if((a==4 || a==6 ||a==9 ||a==11)  &&
    (b== 4|| b== 6||b== 9||b== 11))
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }



}
