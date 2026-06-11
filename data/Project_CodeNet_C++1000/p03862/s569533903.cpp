#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int N,x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int64_t cnt=0;
  if(a[0]>x){cnt+=a[0]-x;a[0]=x;}
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]>x){cnt+=a[i+1]+a[i]-x;a[i+1]-=a[i+1]+a[i]-x;}
  }
  cout<<cnt<<endl;
  return 0;
}
