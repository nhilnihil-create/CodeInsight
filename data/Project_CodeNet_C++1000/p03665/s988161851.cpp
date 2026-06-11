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

ll get_comb(ll a, ll b){
  if(comb[a][b]>0) return comb[a][b];
  if(a==b || b==0) return comb[a][b] = 1;
  return comb[a][b] = get_comb(a-1, b-1) + get_comb(a-1, b);
}

int main() {
  for(int i=0;i<55;++i){
    for(int j=0;j<=i;++j){
      get_comb(i, j);
    }
  }
  int N, P;
  cin>>N>>P;
  ll even=0, odd=0;
  int A;
  for(int i=0;i<N;++i){
    cin>>A;
    if(A%2==0) even++;
    else odd++;
  }
  ll ans = 1;
  ll tmpans = 0;
  for(int i=0;i<even;++i) ans *= 2;
  if(P==0){
    for(int i=0;i<=odd;i+=2){
      tmpans += comb[odd][i];
    }
  }
  else{
    for(int i=1;i<=odd;i+=2){
      tmpans += comb[odd][i];
    }
  }
  cout<<ans*tmpans<<endl;
}

