#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
  int n;
  string s;
  cin >> n >> s;
  s+=s.at(0);
  rep(j,4){
    vector<int> a(n);
    a.at(0)=j/2;
    a.at(1)=j%2;
    int c;
    if (s.at(1)=='o') {c=(a.at(0)+a.at(1))%2;}
    else c=(a.at(0)+1-a.at(1))%2;
  for (int i=2;i<n-1;i++){
    a.at(i)=c;
    if (s.at(i)=='o') {c=(a.at(i-1)+a.at(i))%2;}
    else c=(a.at(i-1)+1-a.at(i))%2;
  }
  a.at(n-1)=c;
  if (s.at(n-1)=='o') {
    if ((a.at(n-2)+a.at(n-1))%2!=a.at(0)) continue;
  }
  else if ((a.at(n-2)+1-a.at(n-1))%2!=a.at(0)) continue;
  if (s.at(0)=='o') {
    if ((a.at(n-1)+a.at(0))%2!=a.at(1)) continue;
  }
  else if ((a.at(n-1)+1-a.at(0))%2!=a.at(1)) continue;
  string u;
  rep(i,n){
    if (a.at(i)==0) u.push_back('S');
    else u.push_back('W');
  }
  cout << u << endl;
  return 0;
  }
  cout << -1 << endl;
  }