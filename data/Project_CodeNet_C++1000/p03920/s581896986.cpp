#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <bitset>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
int dp[10000001];

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  dp[1] = 1;
  for(int i = 2; i <= n; i++){
    if(dp[i - 1] * (dp[i - 1] + 1) == 2 * (i - 1))dp[i] = dp[i - 1] + 1;
    else dp[i] = dp[i - 1];
  }
  int curr = n;
  while(curr){
    cout << dp[curr] << endl;
    curr = curr - dp[curr];
  }
	return 0;
}
