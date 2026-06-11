#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

bool ok = true;
vector<bool> used(1e+5 + 1, false);
vec a(1e+5 + 1, 0);
mat G(1e+5 + 1, vec(0));//node : 0 ~ N
int p = 0;
ll dfs(int v){
    used[v] = true;
    ll sum = 0, ma = 0;
    for(int to : G[v]){
        if(!used[to]) {
            ll temp = dfs(to);
            sum += temp;
            ma = max(ma, temp);
        }
    }
    if(sum == ma){
        if(sum != 0 && sum != a[v]) ok = false;
        return a[v];
    }else {
        ma = max(ma, (sum + 1) / 2);
        if (a[v] < ma || sum < a[v]) ok = false;
        return a[v] * 2 - sum;
    }
}

int main() {
    cin>>N;
    rep(i,N) cin>>a[i + 1];
    rep(i,N - 1){
        cin>>A>>B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    reps(i, 1, N + 1) if(G[i].size() == 1) p = i;
    dfs(p);
    cout<<(ok ? "YES" : "NO")<<endl;
}