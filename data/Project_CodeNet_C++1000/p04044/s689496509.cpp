#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, l;
  vector<string> S;
  string ans;
  cin >> n >> l;
  for (int i = 0; i < n; i++)
  {
    string buf;
    cin >> buf;
    S.push_back(buf);
  }
  for (int i = 0; i < n; i++)
  {
    ans += *min_element(S.begin(), S.end());
    int bufIndex = min_element(S.begin(), S.end()) - S.begin();
    S.erase(S.begin() + bufIndex);
  }
  cout << ans << endl;
}
