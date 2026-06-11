#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int h, w, n;
ll ans[10];
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> h >> w >> n;
    map<P, int> p;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        rep(j, 0, 3) rep(k, 0, 3) {
            int va = x-j, vb = y-k;
            if (va <= 0 || h < va + 2 || vb <= 0 || w < vb + 2) continue;
            p[mp(va, vb)]++;
        }
    }
    fill(ans, ans+10, 0);
    ans[0] = (ll)(h-2)*(w-2);
    for (auto itr = p.begin(); itr != p.end(); itr++) {
       ans[itr->second]++;
       ans[0]--;
    }
    rep(i, 0, 10) cout << ans[i] << endl;
    return 0;
}
