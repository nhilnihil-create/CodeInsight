#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 505;

int n;
int t[MAXN];

bool cmp(const int &a, const int &b) {
  return t[a] < t[b];
}

int sol[MAXN * MAXN];

vector<int> avaliable;
vector<int> event[MAXN * MAXN];

int uk[MAXN];

bool check() {
  REP(i, n * n) {
    uk[sol[i]] ++;
    if(t[sol[i]] == i && uk[sol[i]] != sol[i]) {
      cout << "No";
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;

  vector<int> v;

  FOR(i, 1, n + 1) {
    int x; cin >> x;

    t[i] = x - 1;
    REP(j, i - 1) {
      v.push_back(i);
    }

    event[x].push_back(i);
    sol[x - 1] = i;
  }

  sort(v.begin(), v.end(), cmp);

  for(int i = 0, j = 0; i < v.size(); ++i) {
    while(sol[j]) {
      j ++;
    }
    sol[j] = v[i];
  }

  REP(i, n * n) {
    for(auto x: event[i]) {
      REP(j, n - x) {
        avaliable.push_back(x);
      }
    }

    if(!sol[i]) {
      if(avaliable.empty()) {
        cout << "No";
        return 0;
      }
      sol[i] = avaliable.back();
      avaliable.pop_back();
    }
  }

  check();

  cout << "Yes\n";
  REP(i, n * n) {
    cout << sol[i] << " ";
  }
}
