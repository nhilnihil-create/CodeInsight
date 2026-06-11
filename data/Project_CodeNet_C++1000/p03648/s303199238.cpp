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
  ll K;
  cin >> K;
  if (K < 50) {
    cout << 50 << endl;
    cout << 50 * K << " ";
    for (int i = 0; i < 49; i++) {
      cout << 0 << " ";
    }
    cout << endl;
    return 0;
  }

  ll d = K / 50;
  ll r = K % 50;
  ll left = (50 + d - 1) - r;
  ll leftsize = 50 - r;
  ll right = left + 51;
  ll rightsize = r;

  cout << 50 << endl;
  for (int i = 0; i < leftsize; i++) {
    cout << left << " ";
  }
  for (int i = 0; i < rightsize; i++) {
    cout << right << " ";
  }
  cout << endl;
  return 0;
}