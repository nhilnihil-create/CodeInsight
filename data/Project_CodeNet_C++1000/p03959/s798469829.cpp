#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1000000000)
#define MOD (1000000007)
#define PI (acos(-1))

int main(){
  int N;
  cin >> N;
  ll T[100010],A[100010];
  rep(i,N)cin >> T[i];
  rep(i,N)cin >> A[i];
  bool Tkak[100010],Akak[100010];
  Tkak[0]=1;
  Akak[N-1]=1;

  reps(i,1,N){
    if(T[i]!=T[i-1])Tkak[i]=1;
  }
  for(int i=N-2; i>=0; i--){
    if(A[i]!=A[i+1])Akak[i]=1;
  }

  rep(i,N){
    if(Tkak[i] && T[i]>A[i]){
      cout << 0 << endl;
      return 0;
    }
    if(Akak[i] && A[i]>T[i]){
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  rep(i,N){
    if(!Tkak[i] && !Akak[i]){
      ans *= min(T[i],A[i]);
      ans %= MOD;
    }
  }

  cout << ans << endl;
}
