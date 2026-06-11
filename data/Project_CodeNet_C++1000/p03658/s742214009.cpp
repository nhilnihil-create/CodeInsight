#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int k,n;
  cin >> k >> n;
  vector<int> l(k);
  int i;
  for(i=0;i<k;i++) cin >> l[i];
  sort(l.begin(),l.end());
  int cnt = 0;
  for(i=0;i<n;i++) cnt += l[k-i-1];
  cout << cnt << "\n";
  return 0;
}