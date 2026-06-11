#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a.at(i);
  }
  
  sort(a.begin(), a.end());
  if (a.front() == a.back()) {
    int x = a.front();
    if (x == n-1 || 2*x <= n) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (a.front() + 1 == a.back()) {
    int x = count(a.begin(), a.end(), a.front());
    int y = n - x;
    if (a.back() > x && 2*(a.back()-x) <= y) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
