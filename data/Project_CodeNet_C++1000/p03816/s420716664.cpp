#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N,a,cnt=0;
  cin >> N;
  vector<int> A(1e5+1,0);
  rep(i,N) {
    cin >> a;
    if (A[a]) cnt++;
    A[a]++;
  }
  cout << N-cnt-cnt%2 << endl;
} 