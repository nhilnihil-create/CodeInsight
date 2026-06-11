#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int N, L;
  cin >> N >> L;
  string s[N];

  for (int i = 0; i < N; i++)
    cin >> s[i];

  sort(s, s + N);

  string ans;

  for (int i = 0; i < N; i++)
    ans += s[i];

  cout << ans << endl;
}
