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
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  map<int,int>k;
  for(int i=0;i<N;i++){
    k[a[i]+1]++;
    k[a[i]]++;
    k[a[i]-1]++;
  }
  int MAX=0;
  for(auto c:k){
    if(c.second>MAX){MAX=c.second;}
  }
  cout<<MAX<<endl;
  return 0;  
}