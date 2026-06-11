#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end



int main(){
   int n; cin>>n;
   ll res=0,sum=0;
   rep(i,0,n){
      int x; cin>>x;
      sum+=x;
      if(x==0){
         res+=sum/2;
         sum=0;
      }
   }
   if(sum)res+=sum/2;
   cout<<res<<endl;
   return 0;
}