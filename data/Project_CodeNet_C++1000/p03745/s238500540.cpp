#include <bits/stdc++.h>
using namespace std;

int keta(int num){
  int ans= 0 ;
  int rem;

  for (int i = 4; i >= 0 ; i--){
    rem = pow(10,i);
    ans += (num / rem); 
    num = num % rem;
  }
  return ans;
}


int main() {
  int N;
  cin >> N;

  vector<int64_t> ar(N);
  int inc = 0; //単調増加/現象の判定
  int ans = 1;


  for(int i = 0; i < N; i++){
    cin >> ar[i];
  }

  for(int i = 1; i < N; i++){
    if (ar[i-1] < ar[i]){
      if(inc == 0) inc = 1;
      if(inc == -1){
        ans ++;
        inc = 0;
      }
      
      
    }else if(ar[i-1] > ar[i]){
      if(inc == 0) inc = -1;
      if(inc == 1){
        ans ++;
        inc = 0;
      }
    }
  }

  cout << ans << endl;
}
