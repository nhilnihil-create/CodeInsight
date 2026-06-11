#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){

  int n;
  cin >> n;
  vector<int> v(100100,0);
  REP(i,n){
    int x;cin >> x;
    v[x]++;
  }
  vector<int> a;
  ll res = 0;
  for(int i = 1;i <= 100000;i++){
    if(v[i] & 1)res++;
    else if(v[i])a.push_back(i);
  }
  (int)a.size() & 1 ? res += max(0,(int)a.size()-1) : res += a.size();
  cout << res << endl;





  return 0;
}