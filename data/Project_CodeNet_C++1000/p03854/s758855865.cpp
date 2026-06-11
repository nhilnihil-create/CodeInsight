#include <bits/stdc++.h>
using namespace std;

string s1 = "dream";
string s2 = "dreamer";
string s3 = "erase";
string s4 = "eraser";

bool calc(string S)
{
  while (1)
  {
    if (S.substr(0, s2.size()) == s2)
    {
      if (S.substr(0, s1.size() + s4.size()) == s1 + s4)
      {
        S.erase(0, s1.size() + s4.size());
      }
      else if (S.substr(0, s1.size() + s3.size()) == s1 + s3)
      {
        S.erase(0, s1.size() + s3.size());
      }
      else
      {
        S.erase(0, s2.size());
      }
    }
    else if (S.substr(0, s1.size()) == s1)
    {
      S.erase(0, s1.size());
    }
    else if (S.substr(0, s4.size()) == s4)
    {
      S.erase(0, s4.size());
    }
    else if (S.substr(0, s3.size()) == s3)
    {
      S.erase(0, s3.size());
    }
    else
    {
      return false;
    }
    if (S.size() == 0)
    {
      return true;
    }
  }
}

int main()
{
  string S, T;
  bool flag = false;
  cin >> S;

  flag = calc(S);
  flag ? cout << "YES" << endl : cout << "NO" << endl;
}
