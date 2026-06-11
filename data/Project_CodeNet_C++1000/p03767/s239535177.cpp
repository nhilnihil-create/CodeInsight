#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int n;
  vector<ll> a;

  cin >> n; n*= 3;
  while (n--) {
    ll k;
    cin >> k;

    a.pb(k);
  }

  sort(a.begin(), a.end(), greater<ll>());

  // 5 2 8 5 1 5
  // 8 5 5 5 2 1
  ll res = 0;
  for (int i = 0; i < a.size()/3; ++i) {
  	res += a.at(i*2+1);
  } 

  cout << res << endl;
  return 0;
}
