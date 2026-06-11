#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int,int> m;
    REP(i,N) {
        cin >> A[i];
        m[A[i]] += 1;
    }
    
    vector<ll> v;
    for ( auto a: m){
        int num = a.second;
        int r = a.first;
        if ( num >= 4 ) {
            v.push_back(r);
            v.push_back(r);
        } else if ( num >= 2 ) {
            v.push_back(r);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    
    
    ll ans = 0;
    if ( v.size() >= 2 ){
        ans = v[0] * v[1];
    }
    
    cout << ans << endl;
    
    return 0;
}
