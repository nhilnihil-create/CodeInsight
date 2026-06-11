#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
using namespace std;
typedef long long ll;
const ll INF = 100100100100100100;

ll calc1(ll s1, ll s2, ll mid){
  ll S1 = mid * s2;
  ll S2 = (s1-mid) * (s2/2);
  ll S3 = (s1-mid) * (s2 - s2/2);
  ll Smax = max(S1, max(S2, S3));
  ll Smin = min(S1, min(S2, S3));
  return Smax-Smin;
}

ll calc2(ll s1, ll s2, ll mid){
  ll S1 = mid * s2;
  ll S2 = (s1-mid)/2 * s2;
  ll S3 = (s1 - mid - (s1-mid)/2) * s2;
  ll Smax = max(S1, max(S2, S3));
  ll Smin = min(S1, min(S2, S3));
  return Smax-Smin;
}

int main()
{
  ll H,W;
  ll res=INF;
  cin >> H>>W;

  ll s1 = max(H,W);
  ll s2 = min(H,W);

  for(ll i=1;i<s1;i++){
    res = min(res, min(calc1(s1,s2,i),calc2(s1,s2,i)));
  }

  for(ll i=1;i<s2;i++){
    res = min(res, min(calc1(s2,s1,i),calc2(s2,s1,i)));
  }

  cout << res << endl;
}
