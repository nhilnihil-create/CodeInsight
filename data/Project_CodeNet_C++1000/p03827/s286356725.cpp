#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int N;
  cin>>N;
  string s;
  cin>>s;
  int sum=0;
  int MAX=0;
  for(int i=0;i<N;i++){
    if(s[i]=='I'){sum++;}
    else{sum--;}
    chmax(MAX,sum);
  }
  cout<<MAX<<endl;
  return 0;
}