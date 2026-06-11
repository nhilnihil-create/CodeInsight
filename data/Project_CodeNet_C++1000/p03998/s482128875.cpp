#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s[3];
    rep(i, 3) cin >> s[i];
    int index[3] = {0, 0, 0};
    int now = 0;
    char ans;
    while (1) {
        if (index[now]==s[now].size()) {
            ans = 'A' + now;
            break;
        }
        int next = s[now][index[now]] - 'a';
        index[now]++;
        now = next;
    }
    
    cout << ans << endl;
    return 0;
}
