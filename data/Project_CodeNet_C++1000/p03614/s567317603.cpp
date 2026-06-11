#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define REPS(i,n) for(int i=1;i<=(n);i++)
#define RREPS(i,n) for(int i=(n);i>0;i--)
#define mp make_pair
#define pb(a) push_back(a)
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> p(N+1);
  REPS(i,N) cin >> p[i];
  int ans = 0;
  REPS(i,N){
    if(p[i] == i){
      ans++;
      if(i < N) swap(p[i],p[i+1]);
    }
  }
  cout << ans << endl;
  return 0;
}
