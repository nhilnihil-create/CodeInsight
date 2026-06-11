#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i;
  vector<int> a(n+1);
  int cnt = 0;
  for(i=1;i<=n;i++) cin >> a[i];
  for(i=1;i<=n;i++){
    if(i==a[a[i]]) cnt++;
  }
  cout << cnt/2 << "\n";
  return 0;
}