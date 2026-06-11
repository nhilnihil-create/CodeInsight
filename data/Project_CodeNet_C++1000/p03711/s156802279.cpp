#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    if((n==2)&&(m==2))
    {
        cout<<"Yes"<<endl;
    }
    else if((n==1||n==3||n==5||n==7||n==8||n==10||n==12)&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
    {
        cout<<"Yes"<<endl;

    }
    else if((n==4||n==6||n==9||n==11)&&(m==4||m==6||m==9||m==11))
    {
       cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
return 0;
}
