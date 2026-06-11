#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll n;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    for(int i=n;i>=1;i-=2){
        cout<<l1[i]<<" ";
    }
    if(n&1){
        for(int i=2;i<=n;i+=2)cout<<l1[i]<<" ";
    }
    else for(int i=1;i<=n;i+=2)cout<<l1[i]<<" ";

    return 0;
}
