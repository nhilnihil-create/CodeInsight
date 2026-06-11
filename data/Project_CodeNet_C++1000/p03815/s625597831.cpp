#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll x;
  cin >> x;

  int y=0;
  if(x%11<=6&&x%11!=0){
    y=1;
  }else if(x%11<=10&&x%11>=7){
    y=2;
  }
  cout << (x/11)*2+y << endl;
}