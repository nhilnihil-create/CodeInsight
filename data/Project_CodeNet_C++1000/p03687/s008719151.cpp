#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> last(26,-1), m(26);
  for (int i = 0; i != n; ++i) {
    auto ic = s[i] - 'a';
    m[ic] = max(m[ic], i - last[ic]);
    last[ic] = i;    
  }
  for (int i = 0; i != 26; ++i) m[i] = max(m[i], n - last[i]);
  cout << *min_element(begin(m),end(m)) - 1 << endl;
}

