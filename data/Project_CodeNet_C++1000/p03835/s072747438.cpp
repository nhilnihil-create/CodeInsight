#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int K,S;
  cin>>K>>S;
  int cnt=0;
  for(int x=0;x<=K;x++){
    for(int y=0;y<=K;y++){
      int z=S-x-y;
      if(z>=0&&z<=K){cnt++;}
    }
  }
  cout<<cnt<<endl;
  return 0;  
}