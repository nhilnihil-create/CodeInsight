#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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

ll DP[55][55];

ll comb(int A, int B) {
  if(DP[A][B]>0) return DP[A][B];
  if(A<B) return 0;
  if(B==0) return DP[A][B] = 1;
  return DP[A][B] = comb(A-1, B-1) + comb(A-1, B);
}

int main() {
  ll N;
  double A, B;
  cin>>N>>A>>B;
  vector<double> arr(N);
  for(ll i=0;i<N;++i) cin>>arr[i];
  sort(arr.begin(), arr.end(), greater<ll>());
  if(arr[0]==arr[A-1]) {
    ll num = 0;
    double ans = 0;
    for(ll i=0;i<A;++i) {
      ans += arr[i];
    }
    for(ll i=0;i<N;++i) {
      if(arr[i]==arr[0]) num++;
    }
    ll ans1 = 0;
    for(ll i=A;i<=B;++i) {
      ans1 += comb(num, i);
    }
    cout<<setprecision(20)<<ans/A<<endl;
    cout<<ans1<<endl;
  }
  else {
    double ans = 0;
    ll num1 = 0, num2 = 0;
    for(ll i=0;i<A;++i) ans += arr[i];
    for(ll i=0;i<N;++i) {
      if(arr[i]==arr[A-1]) num1++;
      if(arr[i]==arr[A-1] && i<A) num2++;
    }
    cout<<setprecision(20)<<ans/A<<endl;
    cout<<comb(num1, num2)<<endl;
  }
}

