#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  if(s == t) {
    cout << s.size() << endl;
    return 0;
  }
  int same = 0;
  string tmp = "";
  for(int i = 0; i < t.size(); i++) {
    tmp += t[i];
    if(s.find(tmp) <= s.size()) {
      same++;
    }else {
      break;
    }
  }
  cout << s.size() + t.size() - same << endl;
  return 0;
}