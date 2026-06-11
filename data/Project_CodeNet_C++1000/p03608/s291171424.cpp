#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef long double ld;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
#define VV(T) vector<vector<T>>
#define sz(x) int(x.size())
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i,n) for (ll i=(ll)n-1;i>=0;i--)
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX6 1001001//6
#define MAX7 10010010//7
#define SENTINEL 2000000000//9
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define CLR(mat) memset(mat, 0, sizeof(mat))
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}//最大公約数
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}//最小公倍数
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
const int MOD = 1000000007;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17
//push_back -> emplace_back
const int MAX_V=210;
ll d[MAX_V][MAX_V];
int V;
void worshall_floyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}



int main(){
   int n,m,r;
   cin>>n>>m>>r;
   V=n;
   VI R(r);
   rep(i,r){cin>>R[i];R[i]--;}
   sort(ALL(R));
   rep(i,n)rep(j,n)d[i][j]=INFTY;
   rep(i,n)d[i][i]=0;
   rep(i,m){
      ll a,b,c;cin>>a>>b>>c;
      a--;b--;
      d[a][b]=c;
      d[b][a]=c;
   }
   worshall_floyd();
    ll ans=INFTY;
    do{
      ll sum=0;
      rep(i,r-1)sum+=d[R[i]][R[i+1]];
      chmin(ans,sum);
    }while(std::next_permutation(ALL(R)));
    cout<<ans<<endl;
}