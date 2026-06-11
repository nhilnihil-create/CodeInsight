#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;
    vi x(n), y(n), a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];

    int left = 0, under = 0;
    rep(i, n){
        if(a[i] == 1) chmax(left, x[i]);
        else if(a[i] == 2) chmin(w, x[i]);
        else if(a[i] == 3) chmax(under, y[i]);
        else chmin(h, y[i]);
    }

    if(h - under < 0){
        cout << 0 << endl;
        return 0;
    }else if(w - left < 0){
        cout << 0 << endl;
        return 0;
    }

    int all_after = (h - under) * (w - left);

   /*  printf("w = %d, h = %d, left = %d, under = %d\n", w, h, left, under); */

    if(all_after >= 0) cout << all_after << endl;
    else cout << 0 << endl;
}