#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> r(n,0);
  for (int i=0; i<n; i++) {
    cin >>r[i];
    r[i] --;
  }
  int ans = 0;
  for (int i=0; i<n; i++){
    if(r[r[i]]==i){
      ans ++;
      r[r[i]]=-1;
    }
  }
  cout << ans << endl;
}