#include<iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define req(i,n) for(int i = 1;i <= n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a)  (a).begin(),(a).end()
#define fix  fixed << setprecision(10)
const ll INF = (1LL << 60);
string s,t; ll n,m,p, q, ans = 0, sum = 0,r;
const ll MOD = 1000000007;
int main() {
    int a, b, c, d, e, f, i, j, k, l, s = 0, w = 100;
    cin >> a >> b >> c >> d >> e >> f; a *= 100; b *= 100;
    for (i = 0; i <= f; i += a)
        for (j = 0; i + j <= f; j += b)
            for (k = 0; i + j + k <= f; k += c)
                for (l = 0; i + j + k + l <= f; l += d)
                    if (((k + l) * (100 + e) <= e * (i + j + k + l) && s * (i + j + k + l) <= (k + l) * (w + s))) {
                        w = i + j, s = k + l;
                    }
    cout << w + s << " " << s << endl;
}