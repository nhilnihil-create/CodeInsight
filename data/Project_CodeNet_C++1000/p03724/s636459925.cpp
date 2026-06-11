#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n,m; cin >> n >> m;
    int g[n];
    rep(i,n) g[i] = 0;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        g[a-1]++;
        g[b-1]++;
    }
    bool ans = true;
    rep(i,n){
        if(g[i] % 2) ans = false;
    }
    if(ans){
        cout << "YES";
    }else{
        cout << "NO";
    }
}