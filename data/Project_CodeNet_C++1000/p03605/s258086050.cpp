#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string N;
  cin>>N;
  rep(i,2){
    if(N[i]=='9'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}