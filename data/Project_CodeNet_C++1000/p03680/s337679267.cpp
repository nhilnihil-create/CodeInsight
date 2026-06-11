#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF=1e18+1;
const int mod = 1000000007;

int main(){
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
    a[i]--;
  }
  vector<bool>seen(N,false);
  int s=0;
  for(int i=0;i<N;i++){
    if(seen[s]){cout<<-1<<endl;return 0;}
    if(s==1){cout<<i<<endl;return 0;}
    seen[s]=true;
    s=a[s];
  }
  return 0;                       
}