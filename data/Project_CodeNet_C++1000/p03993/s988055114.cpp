#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> ai;
  int res = 0;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    ai.push_back(temp);
  }
  for(int i = 0; i < N; i++) {
    if(ai[i] > 0 && (i + 1) == ai[ai[i] - 1]) {
      ai[ai[i] - 1] = -1;
      res++;
    }
  }
  cout << res;
  return 0;
}