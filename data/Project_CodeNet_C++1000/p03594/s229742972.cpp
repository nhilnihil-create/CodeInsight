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
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
const ll MOD = 998244353;
//const ll MOD = (1e+9) + 7;
const ll INF = 1LL<<60;
typedef pair<ll, ll> P;

int main() {
    cin>>H>>W>>K;
    string s(W, 'R');
    vector<string> ans(H, s);
    vector<char> color = {'R', 'G', 'Y', 'B'};
    ll plus = K * 5000;
    rep(i,H){
        rep(j,W){
            bool a = (i + j + plus)%(K * 2) >= K, b = (i - j + plus)%(K * 2) >= K;
            //cout<<a<<' '<<b<<endl;
            ans[i][j] = color[a * 2 + b];
        }
    }
    rep(i,H) cout<<ans[i]<<endl;
}