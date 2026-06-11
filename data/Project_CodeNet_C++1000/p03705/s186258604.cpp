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
  ll N, A, B;
  cin >> N >> A >> B;
  if(N>=2){
    if(A<=B){
      cout << B*(N-2)+A*(2-N)+1 << endl;
    }else{
      cout << 0 << endl;
    }
  }else{
    if(A==B){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
  }
}