#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;

ll euclid(ll a, ll b){
  while (b>1){
    a = a % b;
    swap(a,b);
  }
  return a;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  
  if (s.length()==2) {
    cout << ((s[0]==s[1]) ? "1 2\n" : "-1 -1\n");
    return 0;
  }

  REP(i, s.length()-2){
    if (s[i]==s[i+1] || s[i+1]==s[i+2] || s[i+2]==s[i]) {
      cout << i+1 << " " << i+3 << "\n";
      return 0;
    } 
  }

  cout << "-1 -1" << "\n";
  return 0;
}
