#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  string a, b, c; cin >> a >> b >> c;
  if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]){
    cout << "YES" <<endl;
  }
  else cout << "NO" << endl;
  system("pause");
}