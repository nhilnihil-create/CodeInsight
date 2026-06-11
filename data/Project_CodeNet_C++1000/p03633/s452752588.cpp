#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1e9;
const int mod = 1000000007;

int main(){
  int N;
  cin>>N;
  int64_t ans=1;
  for(int i=0;i<N;i++){
    int64_t x;
    cin>>x;
    ans=ans/__gcd(ans,x)*x;
  }
  cout<<ans<<endl;
  return 0;                       
}