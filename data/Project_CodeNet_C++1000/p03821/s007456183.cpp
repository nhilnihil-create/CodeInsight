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
  int N; cin >> N;
  ll a[N], b[N];
  rep(i,N) cin >> a[i] >> b[i];

  ll retval = 0;
  for (int i=N-1;i>=0;i--){
    a[i] += retval;
    retval += ((a[i]+b[i]-1)/b[i])*b[i] - a[i];
  }
  cout << retval << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

