#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  ll x;
  ll res=0;
  cin >> x;

  res  = x/11 * 2;
  if(x%11>6) res+=2;
  else if(x%11) res++;

  cout << res << endl;
}
