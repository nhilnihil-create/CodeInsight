#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  rep(i, N)
  {
    cin >> x[i];
  }
  map<pair<int, int>, long long> count;
  count[make_pair(0, 0)]++;
  rep(i, N)
  {
    int card = x[i];
    queue<pair<pair<int, int>, long long>> nums;
    for (auto itr = count.begin(); itr != count.end(); ++itr)
    {
      int num = itr->first.first;
      int card_count = itr->first.second;
      num += card;
      nums.push(make_pair(make_pair(num, card_count + 1), itr->second));
    }
    while (nums.size())
    {
      count[nums.front().first] += nums.front().second;
      nums.pop();
    }
  }

  long long ans = 0;
  for (auto itr = count.begin(); itr != count.end(); ++itr)
  {
    int num = itr->first.first;
    int card_count = itr->first.second;
    if (num == A * card_count)
      ans += itr->second;
  }
  cout << ans - 1 << endl;
  return 0;
}