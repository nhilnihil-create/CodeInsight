#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  ll x, a, b; cin >> x >> a >> b;
  if(x < (a*(-1)) + b){
    cout <<  "dangerous" << endl;
  }
  else{
    if(a*(-1)+b > 0)cout << "safe" << endl;
    else cout << "delicious" << endl;
  }
  system("pause");
}