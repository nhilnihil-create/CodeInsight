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
   int n; scanf("%d",&n);
   vector<int> a(n),b(n);
   rep(i,0,n)a[i]=i*20000+1,b[i]=20000*(n-i);
   int rev[501000];
   rep(i,0,n){
      int tmp; scanf("%d",&tmp); rev[tmp-1]=i;
   }
   rep(i,0,n)b[i]+=rev[i];
   rep(i,0,n)printf("%d ",a[i]); puts("");
   rep(i,0,n)printf("%d ",b[i]);
   return 0;
}