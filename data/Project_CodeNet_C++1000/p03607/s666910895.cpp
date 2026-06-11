#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a[100005],cnt=1,ans=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cnt++;
        }else{
            ans+=(cnt%2);
            cnt=1;
        }
    }
    ans+=(cnt%2);
    cout<<ans;
}