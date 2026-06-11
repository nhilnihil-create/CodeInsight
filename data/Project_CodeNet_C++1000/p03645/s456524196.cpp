#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;
int MAXI = 1e8 + 1;
using vec = vector<int>;

int 
main()
{
  int N, M; cin >> N >> M;
  map<int, int> from;
  vec to(M);
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    if(a == 1) from[b] += 1;
    if(b == N) to.push_back(a);
  }

  for(auto x: to){
    if(from[x] != 0){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;

}