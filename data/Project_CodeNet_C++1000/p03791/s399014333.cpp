// Mujin Programming Challenge 2017
#include <bits/stdc++.h>
//#include "testlib.h"
#define ld long double
#define ll long long int
#define mod 1000000007
#define ll_inf 1000000000000000000
#define int_inf 1000000000
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define eps 1e-9
#define PI acos(-1.0)
#define ii pair<int,int>
#define se second
#define fi first
#define prout(x) cout.precision(x)
using namespace std;
ll a[100010];
vector<ll>v;
int main(){
    int n;
    cin>>n;
    ll c=1;
    ll ans=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<c){
            c=a[i]+1;
            if(v.size()==0)ans=i;
            else ans*=(i-v.size());
            v.pb(i);
            ans=ans%mod;
            continue;
        }
        if(a[i]==a[i-1]+1)a[i]=max(a[i], c);
        else a[i]=c;
        c=a[i]+2;
    }
    if(v.size()==0){
        for(ll i=1;i<=n;i++){
            ans=ans*i;
            ans=ans%mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(ll i=n-v.size();i>=1;i--){
        ans=ans*i;
        ans=ans%mod;
    }
    cout<<ans<<endl;
}
