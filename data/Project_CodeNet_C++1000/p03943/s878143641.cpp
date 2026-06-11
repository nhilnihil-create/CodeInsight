#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 2000000000;

int a, b, c;

int main(){
  cin >> a >> b >> c;
  if(a+b==c||b+c==a||c+a==b) cout << "Yes" <<endl;
  else cout << "No" <<endl;
}