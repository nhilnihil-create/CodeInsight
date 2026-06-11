#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int64_t A,B,C;
  cin>>A>>B>>C;
  if(A%2==0||B%2==0||C%2==0){
    cout<<0<<endl;
  }
  else{
    cout<<min({A*B,A*C,B*C})<<endl;
  }
  return 0;
}