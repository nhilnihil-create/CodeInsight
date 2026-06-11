#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, long long> pdl;

const long double pi = 3.141592653589793;

#define debug(x) cerr << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007

void solve(ll n, vector<int>& answer) {
    if(n == 1) return;
    if(n%2 == 0) {
        solve(n/2, answer);
        int z = answer.size();
        answer.pb(z+1);
    } else {
        solve(n-1, answer);
        int z = answer.size();
        answer.pb(z+1);
        for(int i = z;i > 0;i--) answer[i] = answer[i-1];
        answer[0] = z+1;
    }
}

int main() {
  // freopen("input.in","r",stdin);
  // freopen("output.out","w",stdout);

  ll n;
  cin>>n;n++;

  vector<int> answer;
  solve(n, answer);
  cout<<2*answer.size()<<endl;
  rep(i, answer.size()) cout<<answer[i]<<" ";
  rep(i, answer.size()) cout<<i+1<<" ";

  return 0;
}
