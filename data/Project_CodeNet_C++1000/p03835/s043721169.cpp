#include<bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
  int K,S;
  cin >> K >> S;
  int ans = 0;
  for(int i = 0;i < K+1;i++){
    for(int j = 0;j < K + 1;j++){
      if(S-i-j >= 0 && S-i-j <=K){
        ans++;
      }
    }
  }
  printf("%d\n",ans);
}
  