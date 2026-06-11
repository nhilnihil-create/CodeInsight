#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a.at(i);
    if(a.at(i) == 2) {
    }

  }

  //上から順番にやっていく
  int count = 0;
  int x = a.at(0); //0+1 -> x
  while(count < N) {
    if(x != 2) {
      count++;
      x = a.at(x-1);
    } else {
      cout << count + 1 << endl;
      break;
    }
  }
  if(count >= N) {
    cout << -1 << endl;
  }

  return 0;
}