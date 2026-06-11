#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
#define MAX_N 100000
#define MAX_M 100000
const int MAX = 100100;
const int MOD = 1000000007;
#define vec vector<int>
#define vecll vector<ll>
#define vecllvec vector<vector<ll>>
#define vecb vector<bool>
#define vecBvec vector<vector<bool>>
#define vecst vector<string>
#define vecch vector<char>
#define vecd vector<double>
#define vecvec vector<vector<int>>
#define vecDvec vector<vector<double>>
#define vecHvec vector<vector<char>>
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, m, n) for (int i = m; i < (int)n; ++i)
#define print(x) cout << x << endl
#define INF 1e+9
using P = pair<int, int>;
const string YES = "Yes";
const string NO = "No";
#define MAX_V 1000
#define PI 3.141592653589793
// cout << setprecision(15) << std::fixed;

// テレンス「もしかしてACですかーッ!?」　ジョセフ「Yse! Yse! Yse! Oh~MyGod」

int main()
{
  vector<queue<int>> vect(3);
  string s = " ";
  for (int i = 0; i < 3; i++)
  {
    cin >> s;
    for (int j = 0; j < s.size(); j++)
    {
      // print(s[j]);
      int n = 0;
      if (s[j] == 'a')
      {
        n = 0;
      }
      else if (s[j] == 'b')
      {
        n = 1;
      }
      else
      {
        n = 2;
      }
      vect[i].push(n);
    }
  }

  int now = vect[0].front();
  vect[0].pop();
  while (true)
  {
    int bnow = now;
    if (vect[now].empty())
    {
      if (now == 0)
      {
        print("A");
      }
      else if (now == 1)
      {
        print("B");
      }
      else
      {
        print("C");
      }
      break;
    }
    now = vect[now].front();
    vect[bnow].pop();
  }
}