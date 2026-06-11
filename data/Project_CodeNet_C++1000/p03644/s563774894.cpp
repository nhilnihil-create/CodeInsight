#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int main() {
  int N;
  cin>>N;
  int m=-1;
  int ans=0;
  for(int i=1;i<=N;i++){
    int x=i;int cnt=0;
    while(x%2==0){
      cnt++;
      x/=2;
    }
    if(cnt>m){m=cnt;ans=i;}
  }
  cout<<ans<<endl;
  return 0;
}
