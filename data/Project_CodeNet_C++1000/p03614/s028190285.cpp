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

int n, ans;
bool ok[100005];
vector<int> p;
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> n;
    p.resize(n);
    erep(i, 1, n) {
        cin >> p[i];
        if (p[i] != i) ok[i] = true;
        else ok[i] = false;
    }
    rep(i, 1, n) {
        if (!ok[i]) {
            ans++;
            ok[i] = ok[i+1] = true;
        }
    }
    if (!ok[n]) ans++;
    printf("%d\n", ans);
    return 0;
}
