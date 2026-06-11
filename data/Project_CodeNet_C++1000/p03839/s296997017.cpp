#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

ll rui[101000]={};

int main(){
   int n,k; scanf("%d%d",&n,&k);
   vector<ll> a(n); rep(i,0,n)scanf("%lld",&a[i]);
   rep(i,0,n)rui[i+1]=rui[i]+a[i];
   vector<ll> lb(n+1,0LL),rb(n+1,0LL);
   rep(i,0,n)lb[i+1]=lb[i]+max(0LL,a[i]);
   rrep(i,n,0)rb[i-1]=rb[i]+max(0LL,a[i-1]);
   ll res=0;
   rep(i,0,n-k+1){
      ll sub=max(0LL,rui[i+k]-rui[i])+lb[i]+rb[i+k];
      chmax(res,sub);
   } printf("%lld\n",res);
   return 0;
}