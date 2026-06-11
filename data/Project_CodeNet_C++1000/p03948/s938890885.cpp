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

int n, t, a[100005], bf[100005], ans;
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n >> t;
    rep(i, 0, n) cin >> a[i];
    int min_val = INF;
    rep(i, 0, n) {
        if (min_val > a[i]) min_val = a[i];
        bf[i] = a[i] - min_val;
    }
    int max_val = *max_element(bf, bf+n);
    rep(i, 0, n) {
        if (bf[i] == max_val) ans++;
    }
    cout << ans << endl;
    return 0;
}
