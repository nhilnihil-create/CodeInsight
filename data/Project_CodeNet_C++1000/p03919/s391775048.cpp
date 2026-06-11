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

int h, w;
string s[26][26];
char ans;
int val;
int main() {
 ios::sync_with_stdio ( false );
 cin.tie ( 0 );
    cin >> h >> w;
    rep(i, 0, h) {
        rep(j, 0, w) {
            cin >> s[i][j];
            if (s[i][j] == "snuke") {
                ans = (char)('A' + j);
                val = i + 1;
            }
        }
    }
    cout << ans << val << endl;
    return 0;
}
