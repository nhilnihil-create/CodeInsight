#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  ll a, b; cin >> a >> b;
  if(a <= b)cout << 0 << endl;
  else cout << a-b << endl;
  system("pause");
}