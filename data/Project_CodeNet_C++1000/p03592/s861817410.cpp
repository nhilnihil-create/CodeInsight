#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N,M,K;
  cin >> N >> M >> K;

  int flag = 0;
  REP(i,N+1){
    REP(j,M+1){
      if(i*M+j*N-2*i*j==K){
        flag = 1;
        break;
      }
    }
  }
  if(flag == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}