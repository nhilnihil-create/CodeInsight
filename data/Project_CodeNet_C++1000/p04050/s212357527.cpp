#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "Impossible" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  if (m == 1) {
    int a;
    cin >> a;

    if (a == 1) {
      cout << a << endl;
      cout << 1 << endl;
      cout << 1 << endl;
      return 0;
    }
    cout << a << endl;
    cout << 2 << endl;
    cout << a - 1 << " " << 1 << endl;    
    return 0;
  }

  vector<int> odds;
  vector<int> evs;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;

    if (a % 2 == 0) evs.push_back(a);
    if (a % 2 == 1) odds.push_back(a);
  }

  if ((int) odds.size() > 2) failure();
  
  vector<int> A;
  if (!odds.empty()) {
    A.push_back(odds.back());
    odds.pop_back();
  }
  for (int u : evs) {
    A.push_back(u);
  }
  if (!odds.empty()) {
    A.push_back(odds.back());
    odds.pop_back();
  }

  for (int i = 0; i < (int) A.size(); i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  vector<int> B;
  B.push_back(A[0] + 1);
  for (int i = 1; i < (int) A.size() - 1; i++) {
    B.push_back(A[i]);
  }
  B.push_back(A.back() - 1);
  if (B.back() == 0) B.pop_back();

  cout << (int) B.size() << endl;
  for (int b : B) {
    cout << b << " ";
  }
  cout << endl;
}
