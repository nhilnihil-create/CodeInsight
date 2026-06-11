#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;
  string ss = s.substr(0,4);
  if(ss == "YAKI") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
