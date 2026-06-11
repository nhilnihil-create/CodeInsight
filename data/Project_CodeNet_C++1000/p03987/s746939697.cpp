#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
    int N; cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    REP(i,N) {
        cin >> a[i];
        b[a[i]-1] = i;
    }
    set<int> S; S.insert(N);
    set<int> T; T.insert(1);
    ll ans = 0;
    REP(i,N) {
        int itr1 = *S.lower_bound(b[i]); //cout << itr1 << " ";
        int itr2 = -(*T.lower_bound(-b[i])); //cout << itr2 << endl;
        ans += (ll)(i+1)*(itr1-b[i])*(b[i]-itr2);
        S.insert(b[i]);
        T.insert(-b[i]);
    }
    cout << ans << endl;
}