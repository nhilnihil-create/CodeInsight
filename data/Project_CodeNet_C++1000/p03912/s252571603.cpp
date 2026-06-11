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
//template end

int cnt[100010]={};
int rem[100010]={},sub[100010]={};

int main(){
   int n,m; scanf("%d%d",&n,&m);
   rep(i,0,n){
      int tmp; scanf("%d",&tmp);
      cnt[tmp]++; rem[tmp%m]++;
   }
   rep(i,0,100001)sub[i%m]+=cnt[i]/2;
   int ans=rem[0]/2; if(m%2==0)ans+=rem[m/2]/2;
   rep(i,1,(m+1)/2){
      int add=abs(rem[i]-rem[m-i])/2;
      if(rem[i]<rem[m-i])chmin(add,sub[m-i]);
      else chmin(add,sub[i]);
      ans+=min(rem[i],rem[m-i])+add;
   }
   printf("%d\n",ans);
   return 0;
}