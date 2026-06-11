#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll ara[]={1,2,1,3,1,3,1,1,3,1,3,1};
    ll a,b;
    cin>>a>>b;
    if(ara[a-1]!=ara[b-1])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;

}