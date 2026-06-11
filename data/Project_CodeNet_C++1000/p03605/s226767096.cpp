#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) v.begin(), v.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main() 
{
  int n; cin >> n;
  while(n > 0){
    int k = n % 10;
    n /= 10;
    if(k == 9){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  system("pause");
}