#include <iostream>
#include <algorithm>

using namespace std;
int N;
int main() {
  cin >> N;
  
  int sum = 0;
  int i;
  for(i = 1; sum < N; ++i) {
    sum += i;
  }
  
  int iranai = sum - N;
  for(int j = 1; j < i; ++j) {
    if(j == iranai) continue;
    cout << j << endl;
  }
  return 0;
}
