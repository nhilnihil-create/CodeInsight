#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,s=0; cin>>n;
  vector<int> v(1); for(int i=0;i<n;i++) cin>>a,s+=a,v.push_back(a);
  sort(v.begin(),v.end());
  for(int i=0;i<n+1;i++){
    if((s-v[i])%10!=0){
      cout<<s-v[i]<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
}