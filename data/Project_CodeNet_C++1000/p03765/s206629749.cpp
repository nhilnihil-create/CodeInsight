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
    cin>>S>>T>>Q;
    vec s(S.size() + 1,0), t(T.size() + 1,0); //Aの数
    rep(i,S.size()) s[i+1] = (s[i] + (S[i] == 'A'))%3;
    rep(i,T.size()) t[i+1] = (t[i] + (T[i] == 'A'))%3;
    rep(i,Q){
        cin>>A>>B;
        ll sa = s[B] - s[A - 1], sb = B - A - sa;
        cin>>A>>B;
        ll ta = t[B] - t[A - 1], tb = B - A - ta;
        (sb += 3 - sa)%=3;
        (tb += 3 - ta)%=3;
        cout<<(sb == tb ? "YES" : "NO")<<endl;
    }
}