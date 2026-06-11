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
   int n,x; scanf("%d%d",&n,&x);
   vector<int> a(n); rep(i,0,n)scanf("%d",&a[i]);
   int g=a[0]; rep(i,1,n)g=__gcd(g,a[i]);
   if(x%g!=0||*max_element(ALL(a))<x)puts("IMPOSSIBLE");
   else puts("POSSIBLE");
   return 0;
}