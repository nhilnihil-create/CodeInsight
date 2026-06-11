#include <iostream>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  map<int, int> A;
  rep(i, N) { 
    int a;
    cin >> a;
    A[a] = i;
  }
  
  int idx = 0;
  int count = 0;
  for(auto itr : A) {
    if(idx % 2 != itr.second %2) ++count;
    ++idx;
  }
  
  cout << count / 2 << endl;
  return 0;
}