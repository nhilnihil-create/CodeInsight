#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
 int n,m;
  cin>>n>>m;
  vector<int> x(m),y(m); //1
  rep(i,m) cin>>x[i]>>y[i];
  //////////
  vector<int> num(n,1);//0
  
  vector<bool> red(n,false);//0
  red[0]=true;
  rep(i,m){
    num[x[i]-1]--;
    num[y[i]-1]++;
    if(red[x[i]-1]){
      
     red[y[i]-1]=true; 
      
      if(num[x[i]-1]==0) red[x[i]-1]=false;
    }
  }
  int ans=0;
  rep(i,n){
    if(red[i]) ans++;
  }
  cout<<ans<<endl;
}

