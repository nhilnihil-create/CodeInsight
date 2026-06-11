#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(n*j+m*i-i*j*2==k){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}

