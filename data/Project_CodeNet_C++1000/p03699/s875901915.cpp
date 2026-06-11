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
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0, mi = 111;
    rep(i,n){
        cin >> s[i];
        sum += s[i];
        if(s[i]%10 != 0) chmin(mi, s[i]);
    }
    if(sum%10 != 0) cout << sum << endl;
    else if(mi == 111) cout << 0 << endl;
    else cout << sum - mi << endl;
    return 0;
}