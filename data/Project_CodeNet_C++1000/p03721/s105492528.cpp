#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
using G = vector<map<int, int>>;

int 
main()
{
  int N; cin >> N;
  ll K; cin >> K;
  set<int> s;
  vector<ll> arr(100001);
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    s.insert(a);
    arr[a] += b;
  }

  for(auto x : s){
    K -= arr[x];
    if(K <= 0){
      cout << x << endl;
      return 0;
    }
  }
}