#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll MOD=1e9+7;
ll MAX=1e17;

int tell[100002];
ll factorial[100002];

ll power(ll a, ll b){
    ll x = 1, y = a;
    while (b > 0){
        if (b%2){
            x = (x*y)%MOD;
        }
        y = (y*y)%MOD;
        b /= 2;
    }
    return x%MOD;
}   
 
ll modular_inverse(ll n){
    return power(n, MOD-2);
}
 
ll nCr(ll n, ll k){
    ll flag= ((factorial[n])*(modular_inverse(factorial[k])))%MOD;
    return (flag*modular_inverse(factorial[n-k]))%MOD;
}


int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    n++;
    factorial[0]=1;
    for (int i = 1; i < 100002; ++i)
    {
        factorial[i] = ((ll)i*factorial[i-1])%MOD;
    }
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll rep=0,counter=0;
    for (int i = 0; i < n; ++i)
    {
        if(tell[a[i]]==0) tell[a[i]]=1;
        else {
            rep=a[i];
            break;
        }
    }
    int help=0;
    for (int i = 0; i < n; ++i)
    {
        if(!help){
            if(a[i]!=rep) counter++;
            else help=1;
        }
        else if(help==1){
            if(a[i]==rep) help=-1;
        }
        else counter++;
    }
    cout<<n-1<<endl;
    for (int i = 2; i <= n; ++i)
    {
        ll ans=nCr(n,i);
        if(counter>=i-1) ans-=nCr(counter,i-1);
        cout<<(ans+MOD)%MOD<<endl;
    }
    return 0;
}