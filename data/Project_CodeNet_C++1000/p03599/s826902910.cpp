#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  int cntA = F/(A*100), cntB = F/(B*100);
  set<int> st;
  REP(i, cntA+1){
    REP(j, cntB+1){
      if(i*A*100+j*B*100 > F || i*A*100+j*B*100 == 0) continue; 
      st.emplace(i*A*100+j*B*100);
    }
  }
  double res = 0;
  int ansW = A*100, ansS = 0;
  for(auto i : st){
    int M = min(i/100*E, F-i);
    vector<bool> V(M+1, false);
    V[0] = true;
    REP(j, M+1){
      if(j+C <= M){
        if(V[j]) V[j+C] = V[j];
        if(V[j+C]){
          if(res < double((j+C)*100.0/(j+C+i))){
            res = double((j+C)*100.0/(j+C+i));
            ansW = i;
            ansS = j+C;
          }
        }
      }
      if(j+D <= M){
        if(V[j]) V[j+D] = V[j];
        if(V[j+D]){
          if(res < (((j+D)*100.0/(j+D+i)))){
            res = double((j+D)*100.0/(j+D+i));
            ansW = i;
            ansS = j+D;
          }
        }
      }
    }
  }
  cout << ansW+ansS << " " << ansS << endl;
}