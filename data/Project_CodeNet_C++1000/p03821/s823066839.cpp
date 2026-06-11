#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    ll ans = 0;
    vector<ll> A(n),B(n);
    for(int i=0; i<n; i++){
        cin >> A[i] >> B[i];
    } 
    for(int i=0; i<n; i++){
        A[n-1-i]+=ans;
        ans += (A[n-1-i]%B[n-1-i]==0?0:(B[n-1-i]-A[n-1-i]%B[n-1-i]));
    }    
    cout << ans << endl;
}