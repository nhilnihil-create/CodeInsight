#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int64_t Q,H,S,D,N;
  cin>>Q>>H>>S>>D>>N;
  cout<<min({4*Q,2*H,S})*(N%2)+min(2*min({4*Q,2*H,S}),D)*(N/2)<<endl;
  return 0;}