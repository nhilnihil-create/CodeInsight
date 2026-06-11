#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  int a, b;
  cin >> a >> b;
  if(a==1) a+=14;
  if(b==1) b+=14;
  if(a>b) cout << "Alice" <<endl;
  if(b>a) cout << "Bob" <<endl;
  if(a==b) cout << "Draw" <<endl;
}