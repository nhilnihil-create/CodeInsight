#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int a[310][310], b[310][310];
int n;
int f[310][310];

void warshall_floyd(){
   rep(k, 0, n){
       rep(i, 0, n){
           rep(j, 0, n){
               if(i == k || j == k) continue;
               if(b[i][j] >= b[i][k] + b[k][j]){
                    b[i][j] = b[i][k] + b[k][j];
                    f[i][j] = 0;
               }
           }
       }
   }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
            b[i][j] = a[i][j];
            f[i][j] = 1;
        }
    }
    warshall_floyd();
    int ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            if(a[i][j] != b[i][j]){
                cout << -1 << endl;
                return 0;
            }
            if(f[i][j]) ans += b[i][j];
        }
    }
    cout << ans / 2 << endl;
}