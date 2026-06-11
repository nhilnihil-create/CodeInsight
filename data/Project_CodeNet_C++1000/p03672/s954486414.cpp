#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s;
    cin >> s;
    s.pop_back();
    if (s.size()%2==1) {
        s.pop_back();
    }
    
    while (s.size()) {
        bool ok = true;
        rep(i, s.size()/2) {
            if (s[i]!=s[i+s.size()/2]) ok = false;
        }
        if (ok) {
            cout << s.size() << endl;
            return 0;
        }
        s.pop_back();
        s.pop_back();
    }
    
    
    return 0;
}
