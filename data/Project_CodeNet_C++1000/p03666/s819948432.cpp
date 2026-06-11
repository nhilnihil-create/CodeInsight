#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<utility>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int n,a,b,c,d;
signed main(){
  cin>>n>>a>>b>>c>>d;
  bool ans=false;
  if(a>b){
    swap(a,b);
  }
  int dist=b-a;
  int res=d-c;
  int m=0;
  rep(i,n){
    if((dist<=(d*(n-1-i)-c*i))&&dist>=(c*(n-1-i)-d*i)){
      ans=true;
      break;
    }
  }
  if(ans){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
