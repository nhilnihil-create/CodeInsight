#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};


int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  ll acc = A[0];
  ll ans = 1LL << 62;
  for(int i = 1; i < N; i++) {
    ans = min(ans, abs(acc - (sum - acc)));
    acc += A[i];
  }
  cout << ans << endl;
  return 0;
}