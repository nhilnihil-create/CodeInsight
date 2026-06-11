#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
#define mp make_pair
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
    ll N;
    cin >> N;
    vl T(N),A(N);
    rep(i,N){
        cin >> T[i];
    }
    rep(i,N){
        cin >> A[i];
    }
    vl MXT(N),MNT(N),MXA(N),MNA(N);
    rep(i,N){
        if(i==0){
            MXT[i]=MNT[i]=T[i];
        }
        else{
            if(T[i]<T[i-1]){
                cout << 0 << endl;
                return 0;
            }
            else if(T[i]>T[i-1]){
                MXT[i]=MNT[i]=T[i];
            }
            else{
                MXT[i]=T[i];
                MNT[i]=1;
            }
        }
    }
    per(i,N-1){
        if(i==N-1){
            MXA[i]=MNA[i]=A[i];
        }
        else{
            if(A[i]<A[i+1]){
                cout << 0 << endl;
                return 0;
            }
            else if(A[i]>A[i+1]){
                MXA[i]=MNA[i]=A[i];
            }
            else{
                MXA[i]=A[i];
                MNA[i]=1;
            }
        }
    }
    ll ans=1;
    rep(i,N){
        ans*=max((ll)0,min(MXA[i],MXT[i])-max(MNA[i],MNT[i])+1);
        ans%=MOD;
    }
    cout << ans << endl;
}
