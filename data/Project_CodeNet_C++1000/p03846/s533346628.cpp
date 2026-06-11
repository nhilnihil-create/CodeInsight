#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long X=1000000000+7;  

int main() {
  int n;
  cin>>n;
  bool exist=true;
  if(n%2==0){
    int even[50009];
    rep(i,50009) even[i]=0;
    rep(i,n){
      int a;
      cin>>a;
      if(a%2==0 || a>=n || even[a/2]>1){
        exist=false;
        break;
      }
      even[a/2]++;
    }
  }
  else{
    int odd[50009];
    rep(i,50009) odd[i]=0;
    rep(i,n){
      int a;
      cin>>a;
      if(a%2==1 || a>=n || odd[a/2]>1){
        exist=false;
        break;
      }
      if(a==0 && odd[a/2]!=0){
        exist=false;
        break;
      }
      odd[a/2]++;
    }
  }
  
  if(!exist) cout<<0<<endl;
  else{
    long long ans=1;
    rep(i,n/2)
      ans=(ans*2)%X;
    cout<<ans<<endl;
  }
}