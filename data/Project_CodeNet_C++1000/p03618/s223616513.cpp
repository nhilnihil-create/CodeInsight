#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
 
int main() {
    string A; cin >> A;
    int N = A.size();
    vector<ll> cnt(26);
    REP(i,N) {
        cnt[A[i]-'a']++;
    }
    ll ans = (ll)N*(N+1)/2;
    REP(i,26) {
        ans -= cnt[i]*(cnt[i]+1)/2;
    }
    cout << ans+1 << endl;
    return 0;
}