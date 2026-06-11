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
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    vec x(N);
    rep(i,N) cin>>x[i];
    cin>>L>>Q;
    mat dbl(20,vec(N+1));

    x.push_back(x[N-1] + L);
    rep(i,N + 1){
        dbl[0][i] = --upper_bound(ALL(x), x[i] + L) - x.begin();
    }
    reps(k,1,20) rep(i,N + 1) dbl[k][i] = dbl[k-1][dbl[k-1][i]];
    rep(i,Q){
        cin>>A>>B;
        --A; --B;
        if(A > B) swap(A, B);
        ll res = 0;
        Rrep(j,20){
            if(dbl[j][A] < B){
                A = dbl[j][A];
                res += (1LL<<j);
                //cout<<i<<' '<<j<<' '<<A<<endl;
            }
        }
        cout<<res + 1<<endl;
    }
    /*rep(j,20){
        rep(i,N+1) cout<<dbl[j][i]<<' ';
        cout<<endl;
    }*/
}