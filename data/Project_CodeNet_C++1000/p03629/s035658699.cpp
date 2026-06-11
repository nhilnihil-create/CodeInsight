#include<bits/stdc++.h>
using namespace std;

const int C = 26;

int main() {
  string A;
  cin >> A;

  vector<int> N;
  for(auto& i: A) N.emplace_back(i - 'a');

  vector<set<int>> P(C);
  for(auto i=0; i<N.size(); ++i) P[N[i]].emplace(i);
  for(auto c=0; c<C; ++c) P[c].emplace(N.size());

  auto next = [&](auto i, auto c) {return *P[c].lower_bound(i);};

  vector<int> dp(N.size()+2, N.size());
  dp[N.size()+1] = 0;
  for(int i=N.size(); 0<=i; --i) for(auto c=0; c<C; ++c) dp[i] = min(dp[i], 1 + dp[1 + next(i, c)]);

  for(auto i=0; i<N.size(); ++i) for(auto c=0; c<C; ++c) if(dp[i] == 1 + dp[1 + next(i, c)]) {
    putchar(c + 'a');
    i = next(i, c);
    break;
  }
  cout << endl;
}
