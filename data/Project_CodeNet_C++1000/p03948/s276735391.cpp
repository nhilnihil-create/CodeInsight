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
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<int,int> cnt;
  int mi = 1 << 30;
  for(int i = 0; i < N; i++) {
    mi = min(mi, A[i]);
    cnt[A[i] - mi]++;
  }
  cout << (*(--cnt.end())).second << endl;
  return 0;
}