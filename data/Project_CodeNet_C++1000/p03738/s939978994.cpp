
#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
#define pi acos(-1.0)
#define MAX 1000010
//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
  string a, b;
  cin >> a >> b;
  int alen = a.size();
  int blen = b.size();

  if (alen == blen && a != b) {
    if ((a[0] - '0') > (b[0] - '0')) {
      cout << "GREATER" << endl;
    }
    else{
        cout << "LESS" << endl;
    }
  }

  else if (alen > blen) {
    cout << "GREATER" << endl;
  } else if (alen < blen) {
    cout << "LESS" << endl;
  } else if (a == b) {
    cout << "EQUAL" << endl;
  }

  /* MAIN Code ENDS here: */
}