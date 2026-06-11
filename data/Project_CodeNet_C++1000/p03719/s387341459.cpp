#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (C >= A && C <= B ) {
    cout << "Yes" << endl;
  }

  if (!( C >= A && C <= B )) {
    cout << "No" << endl;
  }

}
