//解説あり
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int k, t;
int mx = -1;

int main(void) {
  cin >> k >> t;
  rep(i, 0, t) {
    int a;
    scanf("%d", &a);
    mx = max(mx, a);
  }
  
  cout << max(mx-1-(k-mx), 0) << endl;
  
  
  
    return 0;
}

