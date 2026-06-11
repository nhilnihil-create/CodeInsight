#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main(){
  int N,M;
  cin>>N>>M;
  map<int,int>k;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    k[a]++;k[b]++;
  }
  for(auto c:k){
    if(c.second%2!=0){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
  return 0;  
}