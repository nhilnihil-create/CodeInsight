#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,k;
  cin >> N >> k;
  vector<int> l(N);
  for (int i = 0; i < N; i++)
  {
    cin >> l.at(i);
  }
  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());

  int sum = 0;
  for (int i = 0; i < k; i++)
  {
    sum += l.at(i);
  }
  cout << sum << endl;
}
