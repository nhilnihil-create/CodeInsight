#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N; cin >> N;
  vector<pair<int, int>> AB(N); REP(i, N) cin >> AB[i].first >> AB[i].second;
  sort(ALL(AB));
  cout << (AB[N-1].first + AB[N-1].second) << endl;
}