#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
vector<int> s;

int main(){
  cin >> n;
  int tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    s.push_back(tmp);
  }
  sort(s.begin(), s.end());
  int sum = accumulate(s.begin(), s.end(), 0);
  for(int i = 0; i < n; i++) {
    if(sum%10 != 0 || sum == 0) {
      break;
    } else if (s[i]%10 != 0) {
      sum -= s[i];
    }
  }
  if(sum%10 == 0 ) sum = 0;
  cout << sum << endl;
  return 0;
}

