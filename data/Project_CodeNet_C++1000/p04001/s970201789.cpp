#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

string s;
ll sum;

void calc(int ind, ll now1, ll now2) {
  int n = s.size();
  if (n == ind) {
    sum += now1 + now2;
    return;
  }

  calc(ind + 1, s.at(ind) - '0', now1 + now2);
  calc(ind + 1, now1 * 10 + (s.at(ind) - '0'), now2);
}


int main() {
  cin >> s;
  calc(0, 0, 0);
  cout << sum / 2ll << endl;
}