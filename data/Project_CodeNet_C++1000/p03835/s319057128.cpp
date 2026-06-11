#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
 
int K,S;
cin >> K >> S;
int ans = 0;
 
rep(i,K+1){
  rep(j,K+1){
    
    if (0<=S-i-j && S-i-j<=K){
      ans+=1;
    }
  }
}
 
cout << ans << endl;
 
return 0;
}