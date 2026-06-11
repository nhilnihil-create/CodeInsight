#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin >> n >> t;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a.at(i);
  
  int ans=t;
  
  for(int i=1;i<n;i++){
    ans+=min(t,a.at(i)-a.at(i-1));
  }
  
  cout << ans << endl;
}