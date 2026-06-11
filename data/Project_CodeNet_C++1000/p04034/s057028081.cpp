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
   int n,m; cin>>n>>m;
   vector<int> a(m),b(m);
   rep(i,0,m){
      cin>>a[i]>>b[i];
      a[i]--; b[i]--;
   }
   vector<int> cnt(n,1);
   set<int> rs; rs.insert(0);
   rep(i,0,m){
      cnt[a[i]]--; cnt[b[i]]++;
      if(rs.count(a[i])){
         rs.insert(b[i]);
         if(cnt[a[i]]==0)rs.erase(a[i]);
      }
   }
   cout<<rs.size()<<endl;
   return 0;
}