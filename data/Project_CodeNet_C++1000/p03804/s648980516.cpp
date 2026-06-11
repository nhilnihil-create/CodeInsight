#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
int n,m;
  cin>>n>>m;
  vector<string> a(n),b(m);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,m){
    cin>>b[i];
  }
  //ぜんたん  
  bool ok=false; 
  for(int i=0;i<=n-m;i++){//hidariue tyoutenn retu
    
      for(int j=0;j<=n-m;j++){//gyou
        bool ng=false;
          for(int k=0;k<m;k++){
            
             for(int l=0;l<m;l++){
               if(ng) break;
                if(a[i+k][j+l]!=b[k][l]) {
                  ng=true;
                }//if
             }//l
            if(ng) break;
          }//k
        
        if(!ng) ok=true;
    }//j
  }//i
  
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}







