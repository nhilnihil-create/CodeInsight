#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    ll h,w;
    string s;
    cin >> h >> w;
    rep(i,w+2){
        cout << "#";
    }
    cout << endl;
    rep(i,h){
        cin >> s;
        cout << "#" << s << "#" << endl;
    }
    rep(i,w+2){
        cout << "#";
    }
    cout << endl;
}