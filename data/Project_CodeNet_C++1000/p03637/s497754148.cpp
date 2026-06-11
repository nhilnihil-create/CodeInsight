#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  vector<long long> A(N);
  long long even4 = 0;
  long long even2 = 0;
  long long odd = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if(A.at(i) % 4 == 0) even4++;
    else if (A.at(i) % 2 == 0) even2++;
    else odd++;
  }

  if (even4 + 1 >= odd && even2 == 0)
    cout << "Yes" << endl;
  else if (even4 >= odd && even2 >= 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
