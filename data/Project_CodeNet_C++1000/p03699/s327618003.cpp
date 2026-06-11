#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  int n;
  cin>>n;
  vin s(n);
  rep(i,n) cin>>s[i];
  //////////////
  int sum=0;
  rep(i,n) sum+=s[i];
  ///////
  
  rep(i,n){
    if(s[i]%10==0){
      s[i]=0; 
    }
    
  }
  sort(all(s));
  rep(i,n){
  	if(sum%10==0){
  	   sum-=s[i];
  	}
    else break;
  }
  if(sum%10!=0)
  cout<<sum<<endl;
  else cout<<0<<endl;
}