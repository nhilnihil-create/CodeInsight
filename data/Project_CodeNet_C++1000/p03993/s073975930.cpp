#include <iostream>
#include <vector>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  int ans = 0;
  rep(i, n){
    int a;
    cin >> a;
    a--;
    v[a].push_back(i);
    for(auto m: v[i]){
      if(m == a) ans++;
    }
  }
  cout << ans << endl;
}

