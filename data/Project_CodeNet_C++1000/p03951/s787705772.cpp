#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  string s, t;
  cin>>N>>s>>t;
  int ans=N;
  for(int i=0; i<N; i++){
    string X=s.substr(i, N-i);
    string Y=t.substr(0, N-i);
  if(X==Y){
    ans=i;
    break;
  }
  }
  // cout<<ans<<endl;
  string Z;
  if(ans==N) Z=s+t;
  else Z=s.substr(0, ans)+t;
  cout<<Z.size()<<endl;
}