#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, t; cin >> n >> t;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  int mi = a[0], ma = 0;
  int ans = 0, dis = 0;
  for(int i=1; i<n; i++){
    if(a[i] < mi){
      mi = a[i];
      ma = 0;
    }
    else{
      if(a[i] - mi > dis){
        ans = 1;
        dis = a[i] - mi;
      }
      else if(a[i] - mi == dis){
        ans++;
      }
      ma = max(ma, a[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
