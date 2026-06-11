#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,2) cout << s[i] << endl;
    }
    return 0;
}