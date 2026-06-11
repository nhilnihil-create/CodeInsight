#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
ll x[100000], L;
int p[100001];
int d[100001][20];
int Q;

signed main(){
    cin >> N;
    rep(i, N) cin >> x[i];
    cin >> L;

    int r = 0;
    rep(i, N-1){
        while(r < N && x[r]-x[i] <= L) r++;
        p[i] = r-1;
    }
    p[N-1] = N;

    rep(j, 20) d[N][j] = N;
    for(int i=N-1; i>=0; i--){
        d[i][0] = p[i];
        rep(j, 19){
            d[i][j+1] = d[d[i][j]][j];
        }
    }

    cin >> Q;
    rep(i, Q){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        a--; b--;
        int ans = 1;
        int j = 19;
        while(d[a][0] < b){
            while(d[a][j] >= b){
                j--;
            }
            ans += (1<<j);
            a = d[a][j];
        }
        cout << ans << endl;
    }
}