#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll t,c=0;
    //cin>>t;
    //while(t--){
        ll n,x=0;ll s=101;
        cin>>n;
        ll l1[n+1];
        for(int i=1;i<=n;i++){
            cin>>l1[i];x+=l1[i];
            if(l1[i]%10!=0)s=min(s,l1[i]);
        }
        
        if(x%10!=0){
            cout<<x;return 0;
        }
        else if(s==101)cout<<0;
        else cout<<x-s;

    return 0;
}
