#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> a(100010);
  for(int i=0;i<n;i++){
    int p;
    cin >> p;
    a[p]++;
    a[p+1]++;
    a[p+2]++;
  }
  
  int ans=0;
  
  for(int i=0;i<100010;i++){
    ans=max(ans,a[i]);
  }
  
  cout << ans << endl;
}