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
  string s[2];
  cin >> n >> s[0] >> s[1];
  ll res = 0;
  bool is;
  if(s[0][0] == s[1][0]){
    is = true;
    res = 3;
    for(int i = 1;i < n;i++){
      if(s[0][i] == s[1][i]){
        if(is){
          res = (res*2)%MOD;
          is = true;
        }else{
          is = true;
        }
      }else{
        if(is){
          res = (res*2)%MOD;
          is = false;
          i++;
        }else{
          res = (res*3)%MOD;
          is = false;
          i++;
        }
      }
    }
  }else{
    is = false;
    res = 6;
    for(int i = 2;i < n;i++){
      if(s[0][i] == s[1][i]){
        if(is){
          res = (res*2)%MOD;
          is = true;
        }else{
          is = true;
        }
      }else{
        if(is){
          res = (res*2)%MOD;
          is = false;
          i++;
        }else{
          res = (res*3)%MOD;
          is = false;
          i++;
        }
      }
    }
  }
  cout << res << endl;



  

  return 0;
}
