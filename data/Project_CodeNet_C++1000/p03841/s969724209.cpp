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
   vector<int> a(n),res(n*n,-1);
   rep(i,0,n){
      scanf("%d",&a[i]);
      a[i]--; res[a[i]]=i;
   }
   vector<int> ord(n); iota(ALL(ord),0);
   sort(ALL(ord),[&](int i,int j){return a[i]<a[j];});
   int lb=0,rb=n*n-1;
   for(int i:ord){
      int cnt=i;
      while(cnt){
         if(res[lb]==-1)res[lb]=i,cnt--;
         else if(lb==a[i]){puts("No"); return 0;}
         lb++;
      }
   }
   sort(ALL(ord),[&](int i,int j){return a[i]>a[j];});
   for(int i:ord){
      int cnt=n-1-i;
      while(cnt){
         if(res[rb]==-1)res[rb]=i,cnt--;
         else if(rb==a[i]){puts("No"); return 0;}
         rb--;
      }
   }
   puts("Yes");
   rep(i,0,n*n)printf("%d ",res[i]+1); puts("");
   return 0;
}