#include <bits/stdc++.h>
using namespace std;
int count_2(int x) {
  int ans = 0;
  while(x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}
int power_2(int x) {
  if(x == 0) {
    return 1;
  }
  else {
  	int ans = 1;
  	for(int i = 0; i < x; i++) {
      ans *= 2;
    }
    return ans;
  }
}
int main() {
  int N;
  cin >> N;
  int num = 0;
  for(int i = 1; i <= N; i++) {
    if(count_2(i) > num) {
      num = count_2(i);
    }
  }
  cout << power_2(num) << endl;
}