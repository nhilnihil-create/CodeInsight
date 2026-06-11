#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,a[100000],b[100000],sun;
  cin>>n;
  vector<pair<int ,int> > pp(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
    pp[i] = make_pair(a[i],b[i]);
  }
  sort(pp.begin(),pp.end());
  sun = pp[n-1].second;
  cout<<pp[n-1].first+sun<<"\n";
  return(0);
}
