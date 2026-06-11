#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int> a(N);
  for(int &x: a) cin>>x;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int ans=0;
  for(int i=0;i<K;i++) ans+=a[i];
  cout<<ans<<endl;
}
  
  