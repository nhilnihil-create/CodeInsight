#include <iostream>
#include <deque>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  deque<int> a;
  for (int i = 0; i != n; ++i) {
    cin >> x;
    if (i % 2) a.push_front(x);
    else a.push_back(x);
  }
  for (int i = 0; i != n; ++i) {
    cout << (i?" ":"")<< a[n%2?n-i-1:i];
  }
  cout << endl;
}
