#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(ll i=(ll)(j);i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(ll)(j);i<=(ll)(n);i++)
#define per(i,j,n) for(ll i=(ll)(j);(ll)(n)<=i;i--)
#define ll long long
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb push_back
#define mp make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=pair<ll,ll>;
const ll MOD=1e9+7;//998244353;
const int MAX=1e5;
const ll INF=(1ll<<62)-1;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,int a){
        for(x;x<=N;x+=(x&-x)) bit[x]+=a;
    }
    int sum(int x){
        int ret=0;
        for(x;x>0;x-=(x&-x)) ret+=bit[x];
        return ret;
    }
};
signed main(){
    int N,K; cin>>N>>K;
    vi dp(N+1);
    rep(i,0,N){
        int X; cin>>X;
        dp[i+1]=dp[i]+X;
    }
    REP(i,0,N) dp[N-i]+=K*i;
    int ans=0;
    vector<pii> Data(N+1);
    REP(i,0,N) Data[i]=std::mp(dp[i],i);
    sort(ALL(Data));
    REP(i,0,N){
        int point=Data[i].second;
        dp[point]=i+1;
    }
    Binary_indexed_tree BIT(N+1);
    REP(i,0,N){
        ans+=BIT.sum(dp[i]);
        BIT.add(dp[i],1);
    }
    cout<<ans<<endl;
}
 
 

