#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s; i<n; ++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

string s = "RGBY";

int main(){

  int h, w, d;
  cin >> h >> w >> d;

  rep(i, h){
    rep(j, w) cout << s[2 * (((i+j) / d) % 2) + ((i-j + d*1000)/ d) % 2];
    cout << endl;
  }

  return 0;
}
