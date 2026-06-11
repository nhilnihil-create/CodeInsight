#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll =  long long;
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

ll MOD=1e9+7;
int main() {
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto & b : a) cin>>b;
    sort(a.begin(),a.end());
    vector<ll> s(n);
    s[0] = a[0];
    for(int i=1;i<n;++i){
        s[i] = s[i-1] + a[i];
    }
    if(s[n-1] < k){
        cout << n << endl;
        return 0;
    }
    int ret = n;
    ll sum = 0;
    for(int i=n-1;i>=0;--i){
        if(sum + a[i] < k){
            sum += a[i];
        }else ret = min(ret,i); 
    }
    cout << ret << endl;
    return 0;
}

