#include<iostream>
#include<vector>

using namespace std;

const static int MAX_N = 100000 + 1;

vector<int> v[MAX_N];
int N;
int da[MAX_N];
int db[MAX_N];

void distanceA(int i, int p, int cnt) {
  if (v[i].size() == 1 && v[i][0] == p) return;

  for (int j = 0; j < v[i].size(); j++) {
    if (v[i][j] == p) continue;
    da[v[i][j]] = cnt;
    distanceA(v[i][j], i, cnt + 1);
  }

  

  return;
}

void distanceB(int i, int p, int cnt) {
  if (v[i].size() == 1 && v[i][0] == p) return;


  for (int j = 0; j < v[i].size(); j++) {
    if (v[i][j] == p) continue;
    db[v[i][j]] = cnt;
    distanceB(v[i][j], i, cnt + 1);
  }

  return;
}

int main() {
  cin >> N;

  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  da[1] = 0;
  distanceA(1, 0, 1);

  db[N] = 0;
  distanceB(N, 0, 1);

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (da[i] <= db[i]) cnt += 1;
  }

  if (cnt > N / 2) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;

  
  return 0;
}
