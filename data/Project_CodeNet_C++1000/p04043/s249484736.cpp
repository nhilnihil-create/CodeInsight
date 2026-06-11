#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    if((n==5&&m==5&&k==7)||(n==5&&m==7&&k==5)||(n==7&&m==5&&k==5))
    	cout<<"YES"<<endl;
    else
    	cout<<"NO"<<endl;
   
    return 0;
}