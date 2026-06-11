#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

using DV = vector<vector<ll>>;

using pqg = priority_queue<ll,vector<ll>, greater<ll> >; // 1,3,5..
using pql = priority_queue<ll,vector<ll> >; //5, 3, 1...

using pqg_p = priority_queue<P,vector<P>, greater<P> >; // 1,3,5..
using pql_p = priority_queue<P,vector<P> >; //5, 3, 1...

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ALL(a)  (a).begin(),(a).end()

struct edge { ll from,to,cost; };

int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);

  int V,E,r;

  cin >> V >> E;

  edge e[E];

  REP(i,E) {
    ll a,b,c;
    cin >> a >> b >> c;

    e[i].from = a-1;
    e[i].to = b-1;
    e[i].cost = -c;
  }




  ll d[V]; //最短


  ll inf = 100000000000000;
  
  REP(i,V) d[i] = inf;
  d[0] = 0;

  REP(v,V-1) {
    bool update = false;
    REP(i,E) {
      edge _e = e[i];
      if (d[_e.from] != inf && d[_e.to] > d[_e.from] + _e.cost) {
        d[_e.to] = d[_e.from] + _e.cost;
        update = true;
      }
    }
    if (!update) break;
  }

  bool negative[V];
  REP(v,V) negative[v] = false;

  REP(v,V) {
    REP(i,E) {
      edge _e = e[i];
      if (d[_e.from] != inf && d[_e.to] > d[_e.from] + _e.cost) {
        d[_e.to] = d[_e.from] + _e.cost;
        negative[_e.to] = true;
      }
      if(_e.from) _e.to=true;
    }
  }
      

  if (negative[V-1]) cout << "inf" << endl;
  else cout << -d[V-1] << endl;

}
