#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int k, t;
    cin >> k >> t;
    int am = 0;
    rep(i, t) {
        int a;
        cin >> a;
        am = max(am, a);
    }
    int b = k - am;
    int ret = (am <= b) ? 0 : am - b -1; 
    cout << ret << endl;
    return 0;
}