#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long ans=1;
  vector<long long> t(n);
  for(int i=0;i<n;i++){
	cin>>t[i];
    ans=lcm(ans,t[i]);
  }
  cout<<ans<<'\n';
}