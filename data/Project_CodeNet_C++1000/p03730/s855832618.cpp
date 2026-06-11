#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  int num=0;
  rep(i,B*A){
    num=A*i;
    if(num%B==C){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}