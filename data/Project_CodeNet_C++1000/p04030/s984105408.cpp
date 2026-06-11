#include <iostream>
using namespace std;

int main()
{

  string s;
  cin >> s;
  int n = s.size();

  string ans;
  int now = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
    {
      ans += '0';
      now++;
    }
    else if (s[i] == '1')
    {
      ans += '1';
      now++;
    }
    else if (s[i] == 'B' && now != 0)
    {
      ans.erase(now - 1);
      now--;
    }
  }

  cout << ans << endl;
}
