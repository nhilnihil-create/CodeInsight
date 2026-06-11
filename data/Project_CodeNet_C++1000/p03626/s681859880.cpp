#include <bits/stdc++.h>
#include <complex>
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

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>S>>T;
    vec code(0);
    char last = S[0];
    ll temp = 0;
    reps(i,1,N){
        if(last != S[i]){
            code.push_back(temp);
            temp = 0;
        }else{
            ++temp;
        }
        last = S[i];
    }
    code.push_back(temp);
    //rep(i,code.size()) cout<<code[i]<<' ';
    ll ans = (code[0] == 1 ? 6 : 3);
    ll lcode = code[0];
    reps(i,1,code.size()){
        if(lcode == 1){
            (ans *= (code[i] == 1 ? 3LL : 1LL))%=MOD;
        }else{
            (ans *= 2LL)%=MOD;
        }
        lcode = code[i];
    }
    cout<<ans<<endl;
}