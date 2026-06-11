#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    rep(i,w+2) cout << '#';
    cout << endl;
    rep(i,h) cout << '#' << a[i] << '#'<< endl;
    rep(i,w+2) cout << '#';
    cout << endl;
    return 0;
}