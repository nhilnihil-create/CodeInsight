#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
string to_str(ll x){string res; while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return res;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end



int main(){
   int n,m; scanf("%d%d",&n,&m);
   vector<int> a(m); int cnt=0;
   rep(i,0,m){
       scanf("%d",&a[i]);
       if(a[i]&1)cnt++;
   }
   if(m==1){
       printf("%d\n",a[0]);
       if(a[0]==1)printf("1\n1\n");
       else printf("2\n%d 1\n",a[0]-1);
       return 0;
   }
   if(cnt>2){printf("Impossible\n"); return 0;}
   int idx[2],cnt2=cnt;
   rep(i,0,m){
       if(a[i]&1){
           cnt--;
           if(cnt==0)idx[0]=i;
           if(cnt==1)idx[1]=i;
       }
   }
   if(cnt2>=1)swap(a[0],a[idx[0]]);
   if(cnt2==2)swap(a[m-1],a[idx[1]]);
   rep(i,0,m)printf("%d ",a[i]); puts("");
   a[0]--; a[m-1]++; vector<int> b;
   rep(i,0,m)if(a[i]>0)b.push_back(a[i]);
   printf("%d\n",b.size());
   rep(i,0,b.size())printf("%d\n",b[i]);
   return 0;
}