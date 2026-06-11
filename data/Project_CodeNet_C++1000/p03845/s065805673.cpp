#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, total, m,p,x;
  int inp;
  map<int,int> t;
  total = 0;
  cin >> n;
  for(int i = 1; i<=n; i++){
    cin >> inp;
    total+= inp;
    t[i]=inp;
  }
  cin >> m;
  while(m){
    cin >> p >> x;
    int ans = t[p]-x;
    ans = total - ans;
    cout << ans << "\n";
    m--;
  }

  return 0;
}
