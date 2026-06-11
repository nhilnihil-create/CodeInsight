#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ll long long

using namespace std;

const int MAXN = 100010;
vector <int> ve[MAXN];
int bio[MAXN];
vector <int> out;

int nadi(int x) {
  for (int y : ve[x]) {
    if (!bio[y]) return y;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  
  int A, B;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    A = a, B = b;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }

  bio[A] = 1;
  bio[B] = 1;
  out.push_back(A);
  out.push_back(B);

  while (nadi(B) != -1) {
    int bb = nadi(B);
    out.push_back(bb);
    bio[bb] = 1;
    B = bb;
  }
  
  reverse(out.begin(), out.end());

  while (nadi(A) != -1) {
    int aa = nadi(A);
    out.push_back(aa);
    bio[aa] = 1;
    A = aa;
  }

  cout << out.size() << "\n";
  for (int x : out) cout << x << " "; cout << "\n";

  return 0;
}