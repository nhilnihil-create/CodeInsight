#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MX = 200005;
bool from1[MX], fromN[MX];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        if(a == 1) from1[b] = true;
        if(b == n) fromN[a] = true;
    }
    for(int i = 1; i <= n; ++i){
        if(from1[i] && fromN[i]){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
