#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  sort(x.begin(),x.end());
  int ans=0;
  for(int i=0;i<k;i++){
    ans+=x[n-1-i];
  }
  cout<<ans;
      
}