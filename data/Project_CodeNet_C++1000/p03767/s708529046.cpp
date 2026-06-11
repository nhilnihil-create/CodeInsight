#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


int main() {
  ll n;
  cin >> n;

  vector<ll> members(n*3);
  rep(i, n*3)  cin >> members[i];
  sort(members.begin(), members.end());
  
  ll index = n*3-1;
  ll sum = 0;
  rep(i, n) {
      if (members[index] == members[i-1]) sum += members[index-2];
      else { sum += members[index-1]; index--;}
      index--;
    //   cout << sum << endl;
  }
  
  cout << sum << endl;
  return 0;
}