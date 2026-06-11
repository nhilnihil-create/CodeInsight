#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int a[100001]={};
  for(int i=0; i<n; i++){
    int ai;
    cin >> ai;
    ai--;
    a[ai] += 1;
  }
  bool minus=false;
  int ans = 0;
  for(int i=0; i<100001; i++){
    if(a[i]>0){
      ans++;
    }
  }
  if(ans%2==0) ans--;
  cout << ans << endl;
  return 0;
}