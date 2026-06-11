#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k, xi;
  int ans = 0;
  cin >> n >> k;

  rep(i, n){
    cin >> xi;
    if(xi < k - xi){
      ans += xi;
    }
    else{
      ans += (k - xi );
    }
  }

  cout << ans * 2 << endl;


}
