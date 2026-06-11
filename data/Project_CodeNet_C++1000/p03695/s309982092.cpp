#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()	{
  long long n = 0;
  cin >> n;
  char x = 'A';
  long long count = 0;
  long long val = 0;
  unordered_set<string> colors;
  for (int i = 0; i < n; i++)	{
    cin >> val;
    if (val >= 1 && val <= 399)
      colors.insert("grey");
    else if (val >= 400 && val <= 799)
      colors.insert("brown");
    else if (val >= 800 && val <= 1199)
      colors.insert("green");
    else if (val >= 1200 && val <= 1599)
      colors.insert("cyan");
    else if (val >= 1600 && val <= 1999)
      colors.insert("blue");
    else if (val >= 2000 && val <= 2399)
      colors.insert("yellow");
    else if (val >= 2400 && val <= 2799)
      colors.insert("orange");
    else if (val >= 2800 && val <= 3199)
      colors.insert("red");
    else
      count++;
  }
  if (colors.size() > 0)
    cout << colors.size() << " " << colors.size() + count << endl;
  else if (count > 0)
    cout << 1 << " " << count << endl;
  else
    cout << 0 << " " << 0 << endl;
  return 0;
}