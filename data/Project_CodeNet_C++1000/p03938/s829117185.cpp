#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <tuple>
#define FOR0(var, max) for (ui (var) = 0; (var) < (max); ++(var))
#define FOR_INV(var, min, max) for (ui (var) = (max) - 1; (var) + 1 > (min); --(var))
#define FORITER(var, iter) for (auto (iter) = (var).begin(); (iter) != (var).end(); (iter)++)
#define FORITER_INV(var, iter) for (auto (iter) = (var).rbegin(); (iter) != (var).rend(); (iter)++)

using namespace std;

using uc = unsigned char;
using ui = unsigned int;
using ul = unsigned long long int;
using si = signed int;
using sl = signed long long int;

const static ul NMAX = 20000;

static ul N;
static ul Pi[NMAX];
static sl Ai[NMAX];
static sl Bi[NMAX];
static sl Ci[NMAX];

bool check(void) {
  FOR0(i, N - 1) {
    if (!((Ai[i] < Ai[i + 1]) && (Bi[i] > Bi[i + 1]) && (Ai[Pi[i]] + Bi[Pi[i]] < Ai[Pi[i + 1]] + Bi[Pi[i + 1]]))) {
      return false;
    }
  }
  return true;
}

void solve(void) {
  FOR0(i, N) {
    Ci[Pi[i]] = i + 1;
  }
  si offsetA = 0;
  si offsetB = 0;
  si aoff = 0;
  FOR0(i, N) {
    Ai[i] = i + 1 + offsetA;
    Bi[i] = 2 * N - i - 1 + offsetB;
    si t = Ci[i] - (Ai[i] + Bi[i]);
    if (t < 0) {
      Bi[i] += t;
      offsetB += t;
    } else {
      Ai[i] += t;
      offsetA += t;
    }
    t = max(abs(Ai[i]), abs(Bi[i]));
    if (aoff < t) {
      aoff = t;
    }
  }
  FOR0(i, N) {
    Ai[i] += aoff + 1;
    Bi[i] += aoff + 1;
  }

}

int main(void) {
  cin >> N;
  FOR0(i, N) {
    cin >> Pi[i];
    Pi[i] -= 1;
  }
  solve();
  FOR0(i, N) {
    cout << Ai[i] << " ";
  }
  cout << endl;
  FOR0(i, N) {
    cout << Bi[i] << " ";
  }
  cout << endl;
  // cout << (check() ? "Yes" : "No") << endl;
  return 0;
}