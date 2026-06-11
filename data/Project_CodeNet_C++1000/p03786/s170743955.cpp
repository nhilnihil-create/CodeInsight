#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> sum(n+1);
    sum[0]=0;
    for(int i=0; i<n; i++) sum[i+1] = sum[i] + a[i];
    int cnt=n;
    for(int i=0; i<n; i++){
        if(2*sum[i]<a[i]){
            cnt=n-i;
        }
    }
    cout<<cnt<<endl;
}