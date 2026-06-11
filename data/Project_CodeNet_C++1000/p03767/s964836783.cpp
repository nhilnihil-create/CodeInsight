#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n;
  long long ans;
  vector<int> v;
  
  cin >> n;
  for (int i=0; i<n*3; i++){
    int t;
    cin >> t;
    v.push_back(-t);
  }
  sort(v.begin(), v.end());
  ans = 0;
  for (int i=0; i<n; i++){
    ans += -v[i*2+1];
  }
  cout << ans << endl;
  return 0;
}
