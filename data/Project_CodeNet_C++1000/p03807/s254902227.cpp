#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  string ans="NO";
  int co=0;
  vector<int> A(N);
  rep(i,N){
    cin>>A[i];
    if(A[i]%2==1){
      co+=1;
    }
  }
  if(co%2==0)ans="YES";
  cout<<ans<<endl;
}