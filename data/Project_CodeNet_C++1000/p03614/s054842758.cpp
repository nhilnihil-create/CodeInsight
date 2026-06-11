#include<iostream>
#include<queue>
#include<bitset>
#include<algorithm>
#include<climits>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> P;
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define dump(a) rep(i,a.size()){ cout<<a[i]<<" "; } cout<<endl;
#define dumparr(a,n) rep(i,n){ cout<<a[i]<<" "; } cout<<endl;
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define INF INT_MAX/3
#define FINF DBL_MAX/3
#define EPS 1e-7
#define OUT1(n1) cout<<n1<<endl
#define OUT2(n1,n2) cout<<n1<<" "<<n2<<endl
#define OUT3(n1,n2,n3) cout<<n1<<" "<<n2<<" "<<n3<<endl
#define OUT4(n1,n2,n3,n4) cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl
#define OUT5(n1,n2,n3,n4,n5) cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<endl
#define OUT6(n1,n2,n3,n4,n5,n6) cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<" "<<n6<<endl
#define OUT(n, ...) OUT##n(__VA_ARGS__)

/* algo: *が隣り合ってるときはそれを同時にやると1手で-2, 単体の*の時は両端のどちらかと交換して-1
 * algo: *
 *
 * 最小性の証明: まず*の個数より
 *
 * *を消すのに最低1swapは必要
 * 組み合わせると少なくなる
 */

int main(){
  ll n;
  ll a[100001];
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }
  ll c = 0;

  rep(i,n-1) {
    if(a[i] == i+1) {
      // swap i, i+1
      ll tmp;
      tmp = a[i];
      a[i] = a[i+1];
      a[i+1] = tmp;
      c++;
    }
  }
  if(a[n-1] == n) {
    // swap n-1, n-2
    ll tmp;
    tmp = a[n-1];
    a[n-1] = a[n-2];
    a[n-2] = tmp;
    c++;
  }
  OUT(1, c);
  return 0;
}
