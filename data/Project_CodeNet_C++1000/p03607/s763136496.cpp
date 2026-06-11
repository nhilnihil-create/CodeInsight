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
    REP(i,N) cin >> A[i];
    
    map<int,int> m;
    
    REP(i,N) m[A[i]] += 1;
    
    int ans = 0;
    for ( auto a: m){
        ans += ( a.second % 2 );
    }
    cout << ans << endl;
    
    return 0;
}
