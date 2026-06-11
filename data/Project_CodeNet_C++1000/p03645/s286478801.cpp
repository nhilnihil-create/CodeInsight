#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {
    int n,m; cin >> n >> m;
    int tmp1,tmp2;
    string ans = "IMPOSSIBLE";
    vector<pair<bool,bool>> c(n);

    rep(i,m) {
        cin >> tmp1 >> tmp2;
        if(tmp1 == 1) c[tmp2-1].first = true;
        if(tmp2 == n) c[tmp1-1].second = true;
    }

    rep(i,n){
        if(c[i].first && c[i].second) ans = "POSSIBLE";
    }
    cout << ans;

    return 0;
}