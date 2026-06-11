#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define P push
#define R return
#define C continue
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define SI size()
#define F first
#define S second
#define W while
using namespace std;
long long MOD=1e9+7;
long long INF=1e16+7;
ll a[100003];
ll m=0;
ll am[100003];
ll p=1  ;
int main(){
    am[1]=1;
    for(int i=2;i<=1e5;i++){
        am[i]=am[i-1]*i;
        am[i]%=MOD;
    }
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    ll res=1;
    for(int i=0;i<n-1;i++){
        ll x=a[i];
        if(x<p){
            res*=m+1;
            res%=MOD;
        }
        else{
            m++;
            p+=2;
        }
    }
    res*=am[m+1];
    res%=MOD;
    cout<<res;
    return 0;
}
