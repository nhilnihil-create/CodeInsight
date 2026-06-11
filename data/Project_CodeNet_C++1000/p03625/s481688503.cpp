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
  priority_queue<ll,vector<ll>,less<ll>> que;
  REP(i,n){
    int x;cin >> x;
    que.push(x);
  }
  ll ov = que.top();que.pop();
  ll a = 0,b = 0;
  REP(i,n){
    if(b)break;
    int nv = que.top();que.pop();
    if(nv == ov){
      if(!a)a = nv;
      else b = nv;
      ov = -1;
    }else{
      ov = nv;
    }
  }

  cout << a*b << endl;




  

  return 0;
}
