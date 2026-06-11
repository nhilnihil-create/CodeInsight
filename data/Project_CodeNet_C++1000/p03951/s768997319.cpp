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
  string s,t;
  cin>>s>>t;
  for(int i=N;i<=2*N;i++){
    string r=s;
    reverse(r.begin(),r.end());
    string p=r.substr(0,2*N-i);
    reverse(p.begin(),p.end());
    if(p==t.substr(0,2*N-i)){
      cout<<i<<endl;return 0;
    }
  }
  return 0;
}