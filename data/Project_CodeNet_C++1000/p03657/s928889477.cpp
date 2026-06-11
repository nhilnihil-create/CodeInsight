#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  bool f = false;
  if(a%3 == 0) f = true;
  if(b%3 == 0) f = true;
  if((a+b)%3 == 0) f = true;
  f ? cout << "Possible" << endl : cout << "Impossible" << endl;
  return 0;
}