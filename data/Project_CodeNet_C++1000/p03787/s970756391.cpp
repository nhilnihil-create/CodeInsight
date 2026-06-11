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
typedef pair<int, int> P;

mat G(1e+5, vec(0));
vec color(1e+5, 0);
bool ifd2 = true, only_one = false;
void dfs(int v, int c){
    color[v] = c;
    if(G[v].empty()){
        only_one = true;
        return;
    }
    for(int to : G[v]){
        if(color[to] == 0){
            dfs(to, -c);
        }else if(color[to] == c){
            ifd2 = false;
        }
    }
}

int main() {
    cin>>N>>M;
    rep(i,M){
        cin>>A>>B;
        --A;
        --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    ll d2{0}, nd2{0}, one{0};
    rep(i,N){
        if(color[i] == 0){
            ifd2 = true;
            only_one = false;
            dfs(i, 1);
            only_one ? ++one : ifd2 ? ++d2 : ++nd2;
        }
    }
    cout<<one * (N * 2 - one) + (d2 + nd2) * (d2 + nd2) + d2 * d2<<endl;
}