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
  ll N,P;
  cin >> N >> P;

  ll x = 0,y = 0;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    if(A[i]%2==0){
      x++;
    }else{
      y++;
    }
  }
  
  ll a = pow(2,x);
  ll b = pow(2,y-1);
  if(y==0&&P==1){
    cout << 0 << endl;
  }else if(y==0&&P==0){
    cout << a << endl;
  }else if(x==0&&y==1&&P==0){
    cout << 0 << endl;
  }else if(x==0&&y==1&&P==1){
    cout << 1 << endl;
  }else{
    cout << a*b << endl;
  }
}