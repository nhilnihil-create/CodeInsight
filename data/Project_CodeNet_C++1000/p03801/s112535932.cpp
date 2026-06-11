#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin>>n;
  int a0,ma=0;
  pair<int,int> p[n];
  vector<pair<int,int>> q;
  for(int i=0;i<n;i++){
    cin>>a0;
    p[i]=make_pair(a0,i);
    if(ma<a0){
      q.push_back(make_pair(a0,i));
      ma=a0;
    }
  }
  int ans[n]={},j=0;
  sort(p,p+n);
  ans[q[j].second]+=p[0].first*n;
  for(int i=1;i<n;i++){
    if(q[j].first<p[i].first)j++;
    ans[q[j].second]+=(p[i].first-p[i-1].first)*(n-i);
  }
  for(int i=0;i<n;i++)cout<<ans[i]<<endl;

  
  return 0;
}
