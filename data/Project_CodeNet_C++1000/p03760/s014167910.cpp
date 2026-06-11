#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string o,e;
  cin >> o >> e;
  rep(i, o.length()){
   	if(o[i])
      cout << o[i]; 
    if(e[i])
      cout << e[i]; 
  }
  cout << endl;
  return 0;
}