#include <iostream>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 0;
  cin >> n;
  for(int i =1;i <= n;i++){
    cin >> v[i];
  }
  while(v[pos] != 0 && pos != 2){
    p = pos;
    pos = v[pos];
    v[p] = 0;
    ans++;
  }
  if(pos == 2){
    cout << ans;
  }else{
    cout << -1;
  }
  return 0;
}
