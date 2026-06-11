#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  string a, b, c;
  cin >>a >> b>>c;
  if(a.at(a.size()-1) == b.at(0) && b.at(b.size()-1) == c.at(0)) cout << "YES" <<endl;
  else cout << "NO" <<endl;
}