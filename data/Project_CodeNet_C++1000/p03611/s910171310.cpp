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
    REP(i,N) {
        cin >> A[i];
        A[i] += 1;
    }
    
    vector<int> S(1e+5+2,0);
    
    REP(i,N){
        S[A[i]-1] += 1;
        S[A[i]] += 1;
        S[A[i]+1] += 1;
    }
    
    int ans = 0;
    REP(i,1e+5+2){
        ans = max(ans,S[i]);
    }
    
    cout << ans << endl;
    return 0;
}
