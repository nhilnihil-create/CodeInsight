#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  ll N;
  ll a[1100], t[1100];
  ll res=0;
  cin >> N;

  rep(i,N) {
    cin >> t[i] >> a[i];
  }

  ll T=t[0], A=a[0];
  FOR(i,1,N-1){
    ll n = max(T/t[i] + (T%t[i]>0), A/a[i] + (A%a[i]>0));
    T = t[i] * n;
    A = a[i] * n;
  }
  cout << T + A << endl;
}
