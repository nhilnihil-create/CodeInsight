#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1000000001)
#define MOD (1000000007)
#define PI (acos(-1))

int main(){
  int N,K;
  cin >> N >> K;
  int a[100010];
  rep(i,N){
    cin >> a[i];
  }
  ll sum[100010],psum[100010];
  sum[0] = a[0];
  psum[0] = max(0,a[0]);
  reps(i,1,N){
    sum[i] = sum[i-1]+a[i];
    psum[i] = psum[i-1]+max(0,a[i]);
  }

  ll ans = 0;
  rep(i,N-K+1){
    ll tmp;
    if(i==0 || i==N-1){
      if(i==0)tmp = max((ll)0,sum[K-1])+psum[N-1]-psum[K-1];
      else tmp = psum[N-K-1]+max((ll)0,sum[N-1]-sum[N-K-1]);
    }else{
      tmp = psum[i-1]+max((ll)0,sum[i+K-1]-sum[i-1])+psum[N-1]-psum[i+K-1];
    }
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}