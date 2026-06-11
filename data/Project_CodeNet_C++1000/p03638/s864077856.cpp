#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int H, W, N;
    cin >> H >> W >> N;

    vi colors;
    rep(i, N) {
        int a;
        cin >> a;
        rep(j, a) {
            colors.pb(i+1);
        }
    }

    vvi res(H, vi(W, -1));
    rep(i, H) {
        rep(j, W) {
            int c = colors[i*W+j];
            if(i%2) res[i][W-1-j] = c;
            else res[i][j] = c;
        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}