#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int H, W; cin >> H >> W;
  char num[26] = {};
  rep(i,H) {
    string a; cin >> a;
    rep(j,W) num[a[j]-'a']++;
  }
  int d1 = 0, d2 = 0, d4 = 0;
  rep(i,26) {
    if (num[i]%2) d1++;
    else if (num[i]%4) d2++;
    else d4++;
  }
  
  string result;
  if (H%2&&W%2) {
    result = (d1==1&&d2*2<=H+W-2) ? "Yes" : "No";
  }
  else if (H%2) {
    result = (d1==0&&d2*2<=W) ? "Yes" : "No";
  } 
  else if (W%2) {
    result = (d1==0&&d2*2<=H) ? "Yes" : "No";
  }
  else {
    result = (d1==0&&d2==0) ? "Yes" : "No";
  }
  cout << result << endl;
  return 0;
}