#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  ll Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
  ll cpl = min({4*Q, 2*H, S});
  if (2*cpl<D) cout << cpl*N;
  else {
    if (N%2==1) cout << (N/2)*D + cpl << endl;
    else cout << (N/2)*D << endl;
  }

  // cout << fixed << setprecision(6);
  return 0;
}

