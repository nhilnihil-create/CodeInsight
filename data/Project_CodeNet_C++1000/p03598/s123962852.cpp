#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  
  int target = 0;
  int ans = 0;
  for(int i=0; i<N; i++){
    cin >> target;
    if(K-target < target)ans += (K-target)*2;
    else  ans +=target*2;
  }
  cout << ans << endl;
}