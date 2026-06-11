#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n; cin >> n;
    int t[n+1], total=0;
    reps(i, 1, n+1){
        cin >> t[i];
        total+=t[i];
    }

    int m; cin >> m;
    int p[m+1], x[m+1];
    reps(i, 1, m+1){
        cin >> p[i] >> x[i];
    }

    reps(i, 1, m+1){
        int ans = total - t[p[i]]+x[i];
        out(ans);
    }
}