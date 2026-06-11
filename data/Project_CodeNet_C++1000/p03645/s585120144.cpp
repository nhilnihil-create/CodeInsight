#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
set<int> st[N+1];
int main() {

    ll n,m;
    cin >> n>>m;

    int x, y;
    for (int i = 1; i <= m; i++) {

        cin >> x >> y;
        st[x].insert(y);
        st[y].insert(x);
    }
    bool flag= false;
  for(auto a: st[n])
  {
      if(st[a].empty()== false&&*st[a].begin()==1)
          flag= true;

  }
  if(flag)
      cout<<"POSSIBLE";
  else
      cout<<"IMPOSSIBLE";

}