#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isPossible(x) printf("%s\n",(x) ? "Possible" : "Impossible")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
// #define INF (1<<29)

const long long INF = 1LL<<50;

#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
// const int mod =(int)998244353;
const int mod =(int)1e9+7;

const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(a<0)a=-a;
    if(b<0)b=-b;
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
  if(a<0)a=-a;
  if(b<0)b=-b;
    ll g;g=gcd(a,b);
    return b/g*a;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll RS(ll N,ll P){
    if(P==0){
        return 1;
    }else{
        if(P%2==0){
            ll t=RS(N,P/2);
            return t*t;
        }else{
            return N*RS(N,P-1);
        }
    }
}
int d[3005][3005];
ll dp[3005][3005][4];
int main() {
    ios::sync_with_stdio(false);
    int N=in();
    vector<vi> to(N);
    REP(i,N-1){
        int a,b;
        cin>>a>>b;a--;b--;
        to[a].pb(b);
        to[b].pb(a);
    }
    //1とNの間の経路を調べる
    vi dist_from_1(N,-1);
    dist_from_1[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i:to[now]){
            if(dist_from_1[i]>=0)continue;
            dist_from_1[i]=dist_from_1[now]+1;
            q.push(i);
        }
    }

    q.push(N-1);
    vi dist_from_n(N,-1);
    dist_from_n[N-1]=0;
    bool flg=true;

    int root_n,root_1;
    while(!q.empty()&&flg){
        int now=q.front();q.pop();
        for(int i:to[now]){
            if(dist_from_1[i]<=dist_from_n[now]+1){
                root_1=i;
                root_n=now;
                flg=false;
                break;
            }
            if(dist_from_n[i]!=-1)continue;
            dist_from_n[i]=dist_from_n[now]+1;
            q.push(i);
        }
    }
    //
    vi d(N,0);
    d[root_n]=1;d[root_1]=-1;
    int ans_n=1;
    queue<int> q_n;
    q_n.push(root_n);
    while(!q_n.empty()){
        int now=q_n.front();q_n.pop();
        for(int i:to[now]){
            if(d[i]!=0)continue;
            d[i]=1;
            q_n.push(i);
            ans_n++;
        }
    }
    if(ans_n>=N-ans_n){
        cout<<"Snuke"<<endl;
    }else{
        cout<<"Fennec"<<endl;
    }
    return 0;
} 
 