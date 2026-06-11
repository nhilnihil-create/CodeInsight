#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  const int limit = 1000009;
  int a[limit] = {};
  for(int i = 0; i < n; ++i){
    int tmp; cin >> tmp;
    if(tmp == 0) {
		a[tmp]++;
        a[tmp+1]++;
    }else {
      	a[tmp]++;
      	a[tmp-1]++;
      	a[tmp+1]++;
    }
  }
  int ans = -1;
  for(auto val: a){
    ans = max(ans, val);
  }
  cout << ans << endl;
  return 0;
}