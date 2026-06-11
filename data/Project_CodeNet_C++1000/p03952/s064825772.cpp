#include <bits/stdc++.h>
using namespace std;
deque<int64_t> ans;

void push(int64_t x, vector<bool> &used)
{
  ans.push_back(x);
  used.at(x) = true;
}

int main()
{
  int64_t n, x;
  cin >> n >> x;
  int64_t m = 2 * n - 1;
  if (x == 1 || x == m)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<bool> used(m + 1, false);
  if (n == 2)
  {
    for (int i = 1; i <= 3; i++)
    {
      cout << i << endl;
    }
    return 0;
  }
  if (x == 2)
  {
    push(x + 2, used);
    push(x, used);
    push(x - 1, used);
    push(x + 1, used);
  }
  else
  {
    push(x - 1, used);
    push(x, used);
    push(x + 1, used);
    push(x - 2, used);
  }
  bool front = true;
  for (int i = 1; i <= m; i++)
  {
    if (used[i])
      continue;
    if (front)
      ans.push_front(i);
    else
      ans.push_back(i);
    front = !front;
  }
  while (ans.size())
  {
    cout << ans.front() << endl;
    ans.pop_front();
  }
}
