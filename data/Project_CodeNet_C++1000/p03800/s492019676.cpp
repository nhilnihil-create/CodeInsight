#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N;
string s;
char d[4][2];
vector<string> v = {"S", "W"};

int main () {
  cin >> N;
  cin >> s;

  d[0][0] = 'S';
  d[0][1] = 'W';
  d[1][0] = 'W';
  d[1][1] = 'S';
  d[2][0] = 'W';
  d[2][1] = 'S';
  d[3][0] = 'S';
  d[3][1] = 'W';

  map<string, int> mp;
  mp["SS"] = 0;
  mp["SW"] = 1;
  mp["WS"] = 2;
  mp["WW"] = 3;
  mp["o"] = 0;
  mp["x"] = 1;

  for (auto i: v) {
    for (auto j: v) {
      string ans = i + j;

      Rep(i, N-2) {
        string tmp = ans.substr(i, 2);
        string tmp2 = s.substr(i+1, 1);
        char next = d[mp[tmp]][mp[tmp2]];
        ans += next;
      }

      string tmp = ans.substr(N-2, 2);
      string tmp2 = s.substr(N-1, 1);
      char next = d[mp[tmp]][mp[tmp2]];

      //cout << ans << "\n";
      //cout << next << "\n";
      //cout << ans[0] << "\n";
      
      if (next == ans[0]) {
        string tmp = ans.substr(N-1, 1) + ans.substr(0, 1);
        string tmp2 = s.substr(0, 1);
        char next = d[mp[tmp]][mp[tmp2]];

        if (next == ans[1]) {
          cout << ans << "\n";
          return 0;
        }
      }
    } 
  }
  
  cout << -1 << "\n";

}