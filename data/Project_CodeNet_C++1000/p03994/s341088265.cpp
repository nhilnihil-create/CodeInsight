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
const ll MOD = 1e9 + 7;


int main() {
    string s; 
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<int> ds(n, 0);
    rep(i, n) {
        int d = s[i] == 'a' ? 0 : 'z' - s[i] + 1;
        if (k >= d) {
            k -= d;
        } else ds[i] = s[i] - 'a';
    } 
    if (k > 0) {
        ds[n-1] += k;
        ds[n-1] %= 26;
    }
    string ret = "";
    rep(i, n) ret += ds[i] + 'a'; 
    cout << ret << endl;
    return 0;
}