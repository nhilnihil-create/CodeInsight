#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1e9;
const int mod = 1000000007;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  cout<<s[0]<<n-2<<s[n-1]<<endl;
  return 0;                       
}