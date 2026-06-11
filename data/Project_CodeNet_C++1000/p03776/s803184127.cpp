#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll comb[55][55];

ll getcomb(int a, int b){
  if(comb[a][b]>0) return comb[a][b];
  if(a==b || b==0) return comb[a][b] = 1;
  if(a<b) return 0;
  return comb[a][b] = getcomb(a-1, b-1) + getcomb(a-1, b);
}

int main() {
  for(int i=0;i<55;++i){
    for(int j=0;j<=i;++j){
      getcomb(i, j);
    }
  }
  double N, A, B;
  cin>>N>>A>>B;
  vector<double> v(N);
  for(int i=0;i<N;++i) cin>>v[i];
  sort(v.begin(), v.end(), greater<ll>() );
  double ans = 0;
  ll ans1 = 0;
  if(v[0]==v[A-1]){
    ll numA = 0;
    for(int i=0;i<N;++i){
      if(v[0]==v[i]) numA++;
    }
    ans = v[0];
    for(int i=A;i<=B;++i){
      if(i>numA) break;
      ans1 += comb[numA][i];
    }
  }
  else{
    for(int i=0;i<A;++i) ans += v[i];
    ans /= A;
    ll numA = 0;
    ll supA = 0;
    for(int i=0;i<N;++i){
      if(v[i]==v[A-1]) numA++;
      if(v[i]>v[A-1]) supA++;
    }
    ans1 = comb[numA][ll(A)-supA];
  }
  cout<<setprecision(20)<<ans<<endl;
  cout<<ans1<<endl;
}

