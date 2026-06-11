#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  int t[n];
  int sum = 0;
  for(int i=0;i<n;i++) cin>>t[i],sum+=t[i];
  int m;
  cin>>m;
  while(m--) {
    int p,x;
    cin>>p>>x;
    cout<<sum-t[p-1]+x<<endl;
  }
  return 0;
}