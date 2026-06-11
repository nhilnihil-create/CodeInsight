#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int n,k;
  vector<int> l;
  cin >> n >> k;
  int tmp_l;
  for(int i = 0; i < n; i++){
    cin >> tmp_l;
    l.push_back(tmp_l);
  }
  sort(l.rbegin(), l.rend());
  int ret = 0;
  for(int i = 0; i < k; i++){
    ret += l[i];
  }
  cout << ret << endl;
  return 0;
}
