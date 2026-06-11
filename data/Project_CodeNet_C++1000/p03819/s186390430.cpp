#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

template <class T>
struct BIT_interval {
    vector<T> dat1;
    vector<T> dat2;
    BIT_interval(int n) : dat1(n+1),dat2(n+1) { }
    // add w [l,r)
    void add_interval(int l,int r, T w) {
        for (int k=l+1; k < dat1.size(); k += k&-k) dat1[k] -= w*l;
        for (int k=r+1; k < dat1.size(); k += k&-k) dat1[k] += w*r;
        for (int k=l+1; k < dat2.size(); k += k&-k) dat2[k] += w;
        for (int k=r+1; k < dat2.size(); k += k&-k) dat2[k] -= w;
    }
    T sum(int x) {
        T s = 0;
        for (int k=x; k > 0; k &= k-1) s += dat1[k];
        for (int k=x; k > 0; k &= k-1) s += dat2[k]*x;
        return s;
    }
};

int main() {
  int N,M;cin >> N >> M;
  BIT_interval<int> bit(M+1);
  vector<Pii> A(N);
  repeat(i,N){
    int l,r;
    cin >> l >> r;
    A[i] = {r-l+1,l};
  }
  sort(A.begin(),A.end());
  int idx=0;
  for(int d=1;d<=M;d++){
    while(idx < N && A[idx].first<d){
      int l = A[idx].second;
      int r = l + A[idx].first;
      bit.add_interval(l,r,1);
      idx++;
    }
    int ans = N-idx;
    for(int i=d;i<=M;i+=d){
      ans += bit.sum(i+1)-bit.sum(i);
    }
    cout << ans << endl;
  }
  return 0;
}
