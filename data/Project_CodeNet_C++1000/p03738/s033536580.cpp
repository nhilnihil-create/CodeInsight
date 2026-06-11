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
    string a, b;
    cin >> a >> b;
    string ans = "";
    int na = a.size();
    int nb = b.size();
    if (na>nb) {
        ans = "GREATER";
    }
    else if (na<nb) {
        ans = "LESS";
    }
    else {
        ans = "EQUAL";
        rep(i, na) {
            if (a[i]==b[i]) continue;
            else {
                if (a[i]>b[i]) ans = "GREATER";
                else ans = "LESS";
                break;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
