#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a,b;
  cin >> N;
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    ans = ans + b - a + 1;
  }
  cout << ans << endl;
}