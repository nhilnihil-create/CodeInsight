#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

const int MAX_N = 1e5;
vector<int> es[MAX_N];
bool used[MAX_N];

//nowより下の部分木においてnowを根として同様のゲームを行ったときのgrundy数
int grundy(int now){
    used[now] = true;
    int res = 0;
    for(auto &e: es[now]){
        if(!used[e]) res ^= grundy(e)+1;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    rep(i, N-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        es[a].pb(b), es[b].pb(a);
    }
    fill(used, used+N, false);
    if(grundy(0)) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}