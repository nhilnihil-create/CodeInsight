#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int w, a, b;
    cin >> w >> a >> b;
    int ans = 1e9;
    if(a+w < b) chmin(ans, b - (a+w));
    else if(b+w < a) chmin(ans, a - (b+w));
    else ans = 0;
    cout << ans << endl;
    return 0;
}
