#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }
  vector<bool> seen(n,false);

  int cnt = 0;
  int current = 0;
  while(seen[a[current]] == false){
    seen[a[current]] = true;
    cnt++;
    if(seen[1] == true){
      cout << cnt << endl;
      return 0;
    }
    current = a[current];
  }
  cout << -1 << endl;
  
}
