#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

// O(N log mod)
template<long long MOD=1000000007ll>
struct ModCombination{
    vector<long long> f,fi;
    ModCombination(){}
    ModCombination(int N){
        init(N);
    }

    // x^-1
    long long invp(long long x){
        return mod_pow(x,MOD-2);
    }

    long long mod_pow(long long x,long long n){
        long long res=1;
        while(n){
            if(n&1) res=(res*x)%MOD;
            x=(x*x)%MOD;
            n>>=1;
        }
        return res;
    }

    void init(int N){
        f.resize(N+1);
        fi.resize(N+1);
        f[0]=1;
        for(int i=1;i<N+1;i++) f[i]=(f[i-1]*i)%MOD;
        for(int i=0;i<N+1;i++) fi[i]=invp(f[i]);
    }

    // nCr
    long long get(long long n,long long r){
        long long ret=f[n];
        ret=(ret*fi[r])%MOD;
        ret=(ret*fi[n-r])%MOD;
        return ret;
    }
};

int main(){
    ll h,w,a,b;
    cin >> h >> w >> a >> b;

    ModCombination<> cmb(h+w+2);

    ll ans=0;
    rep(i,w-b){
        int x=i+b; 
        int y=h-a-1;
        ll s=cmb.get(x+y,x);
        x=a-1;
        y=w-b-1-i;
        ll t=cmb.get(x+y,x);
        ans += s*t%mod;
        ans %= mod;
    }
    cout << ans << endl;
}
