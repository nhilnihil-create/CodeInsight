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


int main() {
    int n, m;
    cin >> n >> m;
    vector<int>box(n, 1), x(m), y(m);
     vector<bool>box2(n, false);
    int cnt = 0;
    rep(i, 0, m){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    box2[0] = true;
    rep(i, 0, m){
        box[x[i]]--;
        box[y[i]]++;
        if(box2[x[i]]) box2[y[i]] = true;
        if(box[x[i]]==0) box2[x[i]] = false;
    }
    rep(i, 0, n){
        if(box2[i])cnt++;
        //cout << box2[i] << endl;
    }
    cout << cnt << endl;
}