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
   vector<int> a(n),pos(n+1);
   rep(i,0,n){scanf("%d",&a[i]); pos[a[i]]=i+1;}
   set<int> st; st.insert(0); st.insert(n+1);
   ll ans=0;
   rep(i,0,n){
      ll add=i+1;
      auto it=st.lower_bound(pos[i+1]); it--;
      add*=(pos[i+1]-*it);
      it=st.upper_bound(pos[i+1]);
      add*=(*it-pos[i+1]);
      ans+=add; st.insert(pos[i+1]);
   }
   printf("%lld\n",ans);
   return 0;
}