#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int a, b, c; cin >> a >> b >> c;
  if(a+b == c || a+c == b || b+c== a){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  system("pause");
}