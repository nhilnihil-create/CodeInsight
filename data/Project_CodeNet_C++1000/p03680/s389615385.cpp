#include <iostream>
#include <unordered_set>

using namespace std;

int main()	{
  long long n;
  cin >> n;
  unordered_set<int> buttons;
  long long b[n + 1] = {1};
  long long dest = 1;
  long long curr_button = 1;
  long long nmoves = 0;
  for (long long i = 1; i <= n; i++)	{
    cin >> b[i];
  }
  buttons.insert(1);
  while(1)	{
    if (dest == 2)	{
      break;
    }
    dest = b[dest];
    if (buttons.find(dest) != buttons.end())	{
      cout << -1 << endl;
      break;
    }
    else	{
      buttons.insert(dest);
      nmoves++;
    }
  }
  if (dest == 2)
    cout << nmoves << endl;
  return 0;
}