#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int tmp_a;
    cin >> tmp_a;
    auto itr = find(a.begin(), a.end(), tmp_a);
    if(itr == a.end()) {
      a.push_back(tmp_a);
    } else {
      a.erase(itr);
    }
  }

  cout << a.size() << endl;
  return 0;
}
