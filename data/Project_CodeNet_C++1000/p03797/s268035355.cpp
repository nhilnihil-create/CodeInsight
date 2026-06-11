#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;
/*int dfs(vector<int> &T, vector<int> &C, int i, int sum, int g, int count){
   
}*/

int main(){
  ll n, m;
  cin >> n >> m;
  ll n2 = 2*n;
  if(n2==m) cout << n << endl;
  else if(n2<m){
    m = m-n2;
    m /= 4;
    cout << m+n << endl;
  }
  else{
    cout << m/2 << endl;
  }
}
