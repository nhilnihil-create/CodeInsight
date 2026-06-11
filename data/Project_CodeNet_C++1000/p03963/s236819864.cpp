#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n;
  cin >> n;
  int c;
  cin >> c;
  int ans = 1;
  for(int i=1; i<=n; i++){
    if(i == 1){
      ans *= c;
    }
    else{
      ans *= c-1;
    }
  }
  
  cout << ans << endl;
	return 0;
}
