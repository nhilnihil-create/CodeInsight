#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  int N,M,K;
  cin>>N>>M>>K;
  for(int i=0;i<=N;i++){
	  for(int j=0;j<=M;j++){
		  if(M*i+N*j-2*i*j==K){cout<<"Yes"<<endl;return 0;}
	  }
  }
  cout<<"No"<<endl;
  return 0;
}
