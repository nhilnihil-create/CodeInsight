#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,i;
  cin >> n;
  vector<int> a(n);
  for(i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int cnt = 0;
  int cnt2 = 0;
  for(i=0;i<n-1;i++){
    if(a[i]==a[i+1]) cnt++;
    else{
      if(cnt%2==0) cnt2++;
      cnt = 0;
    }
  }
  if(cnt%2==0) cnt2++;
  cout << cnt2 << "\n";
  return 0;
}