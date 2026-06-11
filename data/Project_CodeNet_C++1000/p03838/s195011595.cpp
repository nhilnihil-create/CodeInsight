#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main(){
  int x,y;
  cin>>x>>y;
  ////////
  ll ans=0;
  ans+=abs(abs(x)-abs(y));
  if(abs(x)<abs(y)){
    if(x<0){
      ans++; 
      if(y<0) {
        ans++;
      }
      
      
    }//x0
   else if(y<0) ans++; 
  }
  
  
  
  else{
    if(x>0){
     ans++;
      if(y>0){
        ans++; 
      }
      
    }
    else if(y>0) ans++;
  }
  
  
  cout<<ans<<endl;
}





