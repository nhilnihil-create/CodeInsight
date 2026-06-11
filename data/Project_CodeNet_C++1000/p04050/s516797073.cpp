#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> even;
vector<int> odd;
vector<int> a;
vector<int> b;

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int t;
    cin >> t;
    if (t & 1) {
      odd.push_back(t);
    } else {
      even.push_back(t);
    }
  }

  if (odd.size() > 2) {
    cout << "Impossible" << endl;
    return 0;
  }

  if (odd.size() == 0) {
    a.push_back(even[0]);
    b.push_back(even[0] - 1);
  } else {
    a.push_back(odd[0]);
    if (odd[0] != 1) {
      b.push_back(odd[0] - 1);
    }
  }

  for (int i=(odd.empty() ? 1 : 0); i < even.size(); ++i) {
    a.push_back(even[i]);
    b.push_back(even[i]);
  }

  if (odd.size() < 2) {
    b.push_back(1);
  } else {
    a.push_back(odd[1]);
    b.push_back(2);
    if (odd[1] != 1) {
      b.push_back(odd[1] - 1);
    }
  }

  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << b.size() << endl;
  for (int i = 0; i < b.size(); ++i) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;

  return 0;
}
