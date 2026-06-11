#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
  string s;
  cin >> s;
  vector<char> answer;
  for (auto i = s.begin(); i != s.end(); i++) {
    if (*i == 'B') {
      if (!answer.empty()) {
        answer.pop_back();
      }
    } else
      answer.push_back(*i);
  }
  for (auto i = answer.begin(); i != answer.end(); i++) {
    cout << *i;
  }
  cout << endl;
}