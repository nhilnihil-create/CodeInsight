#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int size = S.size() - 1;
  long long sum = 0;

  for (int b = 0; b < (1 << size); ++b) {
    vector<int> points;
    for (int i = 0; i < size; ++i) {
      if (b & (1 << i)) {
        points.push_back(i);
      }
    }
    
    int p = 0;
    vector<long long> sums;
    for (int i = 0; i < (int)points.size(); i++) {
      int p0 = points.at(i) + 1;
      sums.push_back(stoi(S.substr(p, p0 - p)));
      p = p0;
    }

    sums.push_back(stoll(S.substr(p)));
	
    for (int i = 0; i < (int)sums.size(); i++) {
      sum += sums.at(i);
    }
  }
  cout << sum << endl;
}