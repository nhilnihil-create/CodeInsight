#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int H, W;
  cin >> H >> W;
  vector<int> alphabet_count(26);
  rep(h, H) rep(w, W)
  {
    char c;
    cin >> c;
    alphabet_count[c - 'a']++;
  }
  int count4 = 0, count2 = 0;
  rep(i, 26)
  {
    count4 += alphabet_count[i] / 4;
    count2 += alphabet_count[i] / 2 - alphabet_count[i] / 4 * 2;
  }

  bool is_ok = true;
  if(count4 >= (H / 2) * (W / 2))
  {
    count4 -= (H / 2) * (W / 2);
    count2 += 2 * count4;
    if(H % 2 == 1 && W % 2 == 0)
    {
      if(count2 == W / 2)
        is_ok = true;
      else
        is_ok = false;
    }
    else if(H % 2 == 0 && W % 2 == 1)
    {
      if(count2 == H / 2)
        is_ok = true;
      else
        is_ok = false;
    }
    else if(H % 2 == 1 && W % 2 == 1)
    {
      if(count2 ==  (H / 2) + (W / 2))
        is_ok = true;
      else
        is_ok = false;
    }
  }
  else
  {
    is_ok = false;
  }

  if(is_ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}