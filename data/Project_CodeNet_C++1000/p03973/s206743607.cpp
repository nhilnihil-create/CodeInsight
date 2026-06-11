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



int main(){
   int n; scanf("%d",&n);
   vector<int> a(n); rep(i,0,n)scanf("%d",&a[i]);
   int p=1; ll res=a[0]-1;
   rep(i,1,n){
      if(a[i]==p+1)p++;
      else if(a[i]>p+1)res+=(a[i]-1)/(p+1);
   }
   printf("%lld\n",res);
   return 0;
}