#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(c-b>a) cout << "dangerous" <<endl;
  if(c-b<=0) cout <<"delicious" <<endl;
  if(0 < c-b && c-b<=a) cout << "safe" <<endl;
}