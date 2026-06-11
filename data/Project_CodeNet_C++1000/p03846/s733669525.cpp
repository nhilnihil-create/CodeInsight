#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin>>n;
  unordered_map<int, int> seen;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    seen[x]++;
  }
  int res = 1;
  for(pair<int, int> freq : seen) {
    int key = freq.first;
    int val = freq.second;
    // case 1: there are not exactly two of the same values
    // case 2: there are more than one or zero 0s if it's even or odd, resp
    // case 3: case 1 and case 2 don't hold so we multiple res by 2;
    if((n&1)==1 && (key&1)==1) {
      cout << 0 << endl;
      return 0;
    }
    if((n&1)==0 && (key&1)==0) {
      cout << 0 << endl;
      return 0;
    }
    if((key == 0) && ((n&1)==1) && (val != 1)) {
      cout << 0 << endl;
      return 0;
    }
    if((key == 0) && ((n&1)==0) && (val != 0)) {
      cout << 0 << endl;
      return 0;
    }
    if(key == 0) {
      continue;
    }
    if(val != 2) {
      cout << 0 << endl;
      return 0;
    }
    res = (res * 2) % (1000000000 + 7);
  }
  cout << res << endl;
  return 0;
}
