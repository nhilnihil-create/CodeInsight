#include <iostream>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int x; cin >> x;
    ans += min(x, abs(x-k));
  }
  cout << 2 * ans << "\n";
  return 0;
}
