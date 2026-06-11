#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
const ll mod = 1e9+7;
const ll inf = 1e17;
const int INF = 1e9;
const double PI = acos(-1);
#define fo(i, a, b) for(int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  string s, t;
  cin >> s >> t;

  if(s.size() > t.size()) cout << "GREATER" << endl;
  else if(s.size() < t.size()) cout << "LESS" << endl;
  else {
    bool equal = true;
    re(i, s.size()) {
      string a = s.substr(i, 1);
      string b = t.substr(i, 1);
      if(stoi(a) > stoi(b)) {
        equal = false;
        cout << "GREATER" << endl;
        break;
      } else if(stoi(a) < stoi(b)) {
        equal = false;
        cout << "LESS" << endl;
        break;
      } else continue;
    }
    if(equal) cout << "EQUAL" << endl;
  }

  return 0;
}
