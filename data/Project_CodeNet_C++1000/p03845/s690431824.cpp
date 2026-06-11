#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int sumVector(vector<int> v, int problem, int time){
  int sum = 0;
  v[problem] = time;
  for(auto c : v) sum += c;
  return sum;
}

int main() {
  int n, m;
  cin >> n;
  vector<int> times(n);
  rep(i, n) cin >> times[i];
  cin >> m;
  vector<int> tottimes(m);
  rep(i, m) {
    int problem, time;
    cin >> problem >> time;
    --problem;
    tottimes[i] = sumVector(times, problem, time);
  }

  for (auto c : tottimes) cout << c << endl;
}