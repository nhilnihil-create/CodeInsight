#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
const double PI = 3.1415926535;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pii>a(m);
    vector<bool>p(200020,false),q(200020,false);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b; 

        if(a == 1)q[b]=true;
        if(b == n)p[a]=true;
    }
    rep(i, 0, 200020){
        if(p[i]&&q[i]){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
     cout << "IMPOSSIBLE" << endl;
}