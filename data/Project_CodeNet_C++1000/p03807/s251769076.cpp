#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int n, ans = 0;
  cin >> n;
  while(cin >> n){
    if(n%2)
      ans++;
  }
  if(ans%2)
    cout << "NO" << endl;
  else cout << "YES" << endl;
}
