#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

bool Solve(vec &d, ll N){
    if(d[N-1]>d[0]+1) return false;
    ll S=d[N-1];
    if(d[N-1]==d[0]){
        if(S==N-1) return true;
        if(S*2>N) return false;
        return true;
    }
    ll One=lower_bound(ALL(d),S)-d.begin();
    ll Two=N-One;
    if(Two==1) return false;
    Two/=2;
    if(S<One+1) return false;
    if(S>One+Two) return false;
    return true;

}
int main(){
    ll N; cin>>N;
    vec d(N);
    rep(i,N) cin>>d.at(i);
    sort(ALL(d));
    if(Solve(d,N)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}