#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  int count=0;
  for(int i=0;i<N;i++){
    string h=s.substr(i);string k;
   for(int j=0;j<N;j++){
     k=t.substr(0,j+1);
     int a=h.size();
     if(h==k){count=max(count,a);}
   }
  }
  string f=s+t;
  cout<<f.size()-count<<endl;
  return 0;}