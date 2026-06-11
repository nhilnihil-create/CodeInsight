#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

const int MAX=1e6+5;

int main() {
  int N,L;
  cin>>N>>L;
  vector<string>s(N);
  for(int i=0;i<N;i++){
    cin>>s[i];
  }
  sort(s.begin(),s.end());
  string t;
  for(int i=0;i<N;i++){
    t+=s[i];
  }
  cout<<t<<endl;
  return 0;  
}