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

void make2(int a,int sz,vector<int>& v){
   vector<int> add(sz,a/sz);
   add.back()+=a%sz;
   rep(i,0,sz)v.push_back(add[i]);
}

vector<int> make(int a,int b){
   vector<int> sub,res(a); int sz=a%b;
   make2(a/b+1,sz,sub); make2(-a/b-2,b-sz,sub);
   rep(i,0,a)res[i]=sub[i%b]; return res;
}

int main(){
   int H,W,h,w; scanf("%d%d%d%d",&H,&W,&h,&w);
   if(H%h==0&&W%w==0){printf("No\n"); return 0;}
   printf("Yes\n");
   bool f=(H%h);
   if(f){
      vector<int> a=make(H,h);
      rep(i,0,H){
         rep(j,0,W)printf("%d ",a[i]);
         puts("");
      }
   }
   else{
      vector<int> a=make(W,w);
      rep(i,0,H){
         rep(j,0,W)printf("%d ",a[j]);
         puts("");
      }
   }
   return 0;
}