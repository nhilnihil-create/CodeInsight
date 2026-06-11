//Code Author: S.M. Istiak Ahmed
#include<bits/stdc++.h>
using namespace std;

const int mxN=100100;
int cnt[mxN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,a;
  cin>>n;
  vector<int> v;
  int ans=0;
  for(int i=0; i<n; i++){
    cin>>a;
    if(!cnt[a]) v.push_back(a);
    cnt[a]++;
  }
  sort(v.begin(),v.end());
  n=v.size();
  for(int i=0; i<n; i++){
    int x=cnt[v[i]];
    if(i+1<n && v[i+1]-1==v[i]) x+=cnt[v[i+1]];
    if(i+2<n && v[i+2]-1==v[i+1]) x+=cnt[v[i+2]];
    ans=max(ans,x);
  }
  cout<<ans;
  return 0;
}