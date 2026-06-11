#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
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

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>A>>B;
    vec v(N);
    rep(i,N) cin>>v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long double ans = 0;
    rep(i,A) ans += v[i];
    long double div = A;
    cout<<fixed<<setprecision(10)<<ans / div<<endl;
    //まずA個選ぶ時の重複
    ll sameV = 0;
    rep(i,N) sameV += v[i] == v[A-1];
    ll num_dif = 0;
    rep(i,A) num_dif += v[i] != v[A-1];
    vec nCm(sameV + 1,1); //sameV C iの値
    reps(i, 1, sameV + 1){
        nCm[i] = ((nCm[i-1] * (sameV - i + 1)) / i);
    }
    ll out = nCm.at(A - num_dif);
    //A個より多く選べる場合
    if(v[0] == v[A-1]){
        reps(i, A, B){
            if(v[i] != v[A-1]) break;
            out += nCm.at(i + 1);
            //cout<<i+1<<' '<<nCm.at(i+1)<<endl;
        }
    }
    cout<<out<<endl;
}