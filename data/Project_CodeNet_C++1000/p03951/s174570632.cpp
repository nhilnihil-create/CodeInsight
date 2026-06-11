#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>

int main() {
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  int ans=2*N;
  for(int i=0;i<N;i++){
    string r;
    //cout<<s.substr(N-1-i)<<" "<<t.substr(0,i+1)<<endl;
    if(s.substr(N-1-i)==t.substr(0,i+1)){
      r=r+s+t.substr(i+1);//  cout<<r<<endl;
      ans=min(ans,(int)r.size());
    }
    
  }
  cout<<ans<<endl;
  return 0;
}