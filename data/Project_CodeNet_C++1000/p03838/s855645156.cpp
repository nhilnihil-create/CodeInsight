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



int main(){
   int x,y; scanf("%d%d",&x,&y);
   ll res=INF;
   rep(f,0,2)rep(g,0,2){
      ll a=x,b=y,sub=0;
      if(f)a*=-1,sub++; if(g)b*=-1,sub++;
      if(a<=b)sub+=b-a,chmin(res,sub);
   } printf("%lld\n",res);
   return 0;
}