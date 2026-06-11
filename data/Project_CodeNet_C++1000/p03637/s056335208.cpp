#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  int n, a = 0, b = 0, c = 0;
  cin >> n;
  rep(i, n){
    ll t;
    cin >> t;
    if(t % 2 != 0) a++;
    else{
      if(t % 4 != 0) b++;
      else c++;
    }
  }
  if(b == 0){
    if(a <= c+1){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else{
    if(a <= c){
      cout << "Yes" << endl;
    }
    else cout << "No" << endl;
  }
  system("pause");
}
