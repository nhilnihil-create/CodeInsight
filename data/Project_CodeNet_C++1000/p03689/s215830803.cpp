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

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    ll h, w;
    cin>>H>>W>>h>>w;
    if((H%h == 0) && (W%w == 0)){
        cout<<"No"<<endl;
    }else {
        mat ans(H, vec(W, 1e+5));
        if(H%h != 0){
            for(int i = h - 1; i < H; i += h){
                rep(j,W) ans[i][j] = -((1e+5) * (h - 1LL)) - 1LL;
            }
        }else{
            for(int j = w - 1; j < W; j += w){
                rep(i,H) ans[i][j] = -((1e+5) * (w - 1LL)) - 1LL;
            }
        }
        cout<<"Yes"<<endl;
        rep(i,H){
            rep(j,W){
                cout<<ans[i][j]<<' ';
                //j != W - 1 ? cout<<' ' : cout<<endl;
            }
            cout<<endl;
        }
    }
}