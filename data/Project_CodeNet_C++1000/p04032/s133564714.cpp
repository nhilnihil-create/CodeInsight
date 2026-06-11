#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

string s;


void solve(){
  cin >> s;
  if(s.size()==2){
    if(s[0]==s[1]){
      cout << 1 << " " << 2 << endl;
      return;
    }
  }

  for(int i=0;i<s.size()-2;i++){
    if(s[i]==s[i+1] || s[i+1]==s[i+2] || s[i]==s[i+2]){
      cout << i+1 << " " << i+3 << endl;
      return;
    }
  }

  cout << -1 << " " << -1 << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
