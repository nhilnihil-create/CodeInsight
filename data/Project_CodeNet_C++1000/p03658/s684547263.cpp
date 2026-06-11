#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll n,k,x=0;
    cin>>n>>k;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    sort(l1+1,l1+n+1,greater<int>());
    for(int i=1;i<=k;i++){
        x+=l1[i];
    }
    cout<<x;

    return 0;
}
