#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
ll a[SIZE];

int main(){
  cin >> n;
  rep(i,0,n) cin >> a[i];
  ll ans = 0;
  ans += a[0]-1;
  a[0] = 1;
  ll mn = 2;
  rep(i,1,n){
    if(mn < a[i]) ans += (a[i]-1)/mn;
    else if(mn == a[i]){
      mn++;
    }
  }
  cout << ans << endl;

  return 0;
}
