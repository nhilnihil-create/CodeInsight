
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N1 = 100000;
int N, T;
int A[MAX_N1];

const int MAX_N = 1 << 17;

int n, dat[2*MAX_N-1];

void init(int n_) {
  n = 1;
  while (n < n_) n *= 2;
  for (int i = 0; i < 2*n-1; ++i) dat[i] = INT_MAX;
}

void update(int k, int a) {
  k += n-1;
  dat[k] = a;
  while (k > 0) {
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1], dat[k*2+2]);
  }
}

//range = [a,b), node number = k, node range = [l, r) 
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INT_MAX;

  if (a <= l && r <= b) return dat[k];
  else {
    int v1 = query(a, b, 2*k+1, l, (l+r)/2);
    int v2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(v1, v2);
  }
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; ++i) cin >> A[i];

  init(N);
  for (int i = 0; i < N; ++i) {
    update(i, A[i]);
  }


  vector<int> prof;
  int max_prof = 0;
  for (int i = N-1; i > 0; --i) {
    int t = A[i] - query(0, i, 0, 0, n);
    max_prof = max(max_prof, t);
    prof.push_back(t);
  }

  sort(all(prof));

  int ans = 0;
  for (int i = prof.size()-1; i >= 0; --i) {
    if (prof[i] < max_prof) break;
    ++ans;
  }

  cout << ans << endl;
}
