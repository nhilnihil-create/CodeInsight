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
  ll A, B, C; cin >> A >> B >> C;
  if (A%2 && B%2 && C%2) cout << min({A*B, B*C, C*A}) << endl;
  else cout << 0 << endl;
  



  // cout << fixed << setprecision(6);
  return 0;
}

