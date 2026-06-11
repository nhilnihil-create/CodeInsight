#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  string s;
  cin >> s;

  int position = s.size() - 1;
  const string dreamer = "dreamer";
  const string dream = "dream";
  const string eraser = "eraser";
  const string erase = "erase";

  bool res = true;
  while (position >= 0) {
    bool isOk = true;

    for (int i = 0; i < dreamer.size(); i++) {
      if (s[position - i] != dreamer[dreamer.size() - i - 1]) isOk = false;
    }
    if (isOk) {
      position -= dreamer.size();
      continue;
    }

    isOk = true;
    for (int i = 0; i < eraser.size(); i++) {
      if (s[position - i] != eraser[eraser.size() - i - 1]) isOk = false;
    }
    if (isOk) {
      position -= eraser.size();
      continue;
    }

    isOk = true;
    for (int i = 0; i < dream.size(); i++) {
      if (s[position - i] != dream[dream.size() - i - 1]) isOk = false;
    }
    if (isOk) {
      position -= dream.size();
      continue;
    }

    isOk = true;
    for (int i = 0; i < erase.size(); i++) {
      if (s[position - i] != erase[erase.size() - i - 1]) isOk = false;
    }
    if (isOk) {
      position -= erase.size();
      continue;
    }

    res = false;
    break;
  }
  cout << (res ? "YES" : "NO") << endl;
}
