#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll cal[n+1];
    cal[0]=0;
    for(ll i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(ll i=0;i<n;i++) cal[i+1]=cal[i]+a[i];
    ll memo=0;
    for(ll i=0;i<n-1;i++){
        if(cal[i+1]*2<a[i+1]) memo=i+1;
    }
    cout << n-memo << endl;
    return 0;
}  
