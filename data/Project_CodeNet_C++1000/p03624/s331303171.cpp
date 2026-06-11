#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i, n) for (int i = 0; i < (n); i ++)
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  vector<int> a(26);
  int n = s.size();
  rep(i, n)
  {
    a.at((int)(s.at(i)) - 97) ++;
  }
  auto it = find(a.begin(), a.end(), 0);
  if (it == a.end()) cout << "None";
  else cout << (char)(distance(a.begin(), it) + 97);
  
  return 0;
}
