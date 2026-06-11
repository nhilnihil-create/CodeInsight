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
  int N,K;
  cin >> N >> K;
  vector<int> A(K);
  REP(i, K) cin >> A[i];
  
  FOR(i,N,100000){
    int flag=0;
    REP(j,K){
      int x = i;
      while(x>0){
        if(x%10==A[j]){
          flag=1;
          break;
        }
        x/=10;
      }
    }
    if(flag==0){
      cout << i << endl;
      break;
    }
  }
}