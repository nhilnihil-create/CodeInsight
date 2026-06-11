#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()
    
void no_cost_graphmake(ll E,mat &G){
  rep(i,E){
    ll a,b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }
}

int main(){
  ll N,M,Q;
  cin >> N >> M;
  mat G(N);
  no_cost_graphmake(M,G);
  cin >> Q;
  vec V(Q),D(Q),C(Q);
  rep(i,Q){
    cin >> V.at(i) >> D.at(i) >> C.at(i);
    V.at(i)--;
  }
  mat A(N,vec(11,0));
  rep(i,Q){
    if(A.at(V.at(Q-1-i)).at(D.at(Q-1-i))!=0){
      continue;
    }
    A.at(V.at(Q-1-i)).at(D.at(Q-1-i))=C.at(Q-1-i);
    queue<P> R;
    if(D.at(Q-1-i)!=0){
      R.push(P(V.at(Q-1-i),D.at(Q-1-i)));
    }
    while(!R.empty()){
      P a=R.front();
      R.pop();
      if(A.at(a.first).at(a.second-1)==0){
        A.at(a.first).at(a.second-1)=C.at(Q-1-i);
        if(a.second-1!=0){
          R.push(P(a.first,a.second-1));
        }
      }
      rep(j,(ll)G.at(a.first).size()){
        if(A.at(G.at(a.first).at(j)).at(a.second-1)==0){
          A.at(G.at(a.first).at(j)).at(a.second-1)=C.at(Q-1-i);
          if(a.second-1!=0){
            R.push(P(G.at(a.first).at(j),a.second-1));
          }
        }
      }
    }
  }
  rep(i,N){
    cout << A.at(i).at(0) << endl;
  }
}
          