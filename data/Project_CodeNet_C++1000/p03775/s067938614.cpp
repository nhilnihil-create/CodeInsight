#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N; cin >> N;
  long long ans = 9999999999;
  int tmp_a = 0;
  int tmp_b = 0;
  for(long long i = 1; i * i <= N; i++){
    if(N % i == 0){
      long long a,b;
      a = i;
      b = N / i;
      //printf("a:%d b:%d\n",a,b);
      while(a > 0){
        a /= 10;
        tmp_a++;
      }
      while(b > 0){
        b /=10;
        tmp_b++;
      }
      
      if(max(tmp_a,tmp_b) < ans) ans = max(tmp_a,tmp_b);
    }
    tmp_a = 0;
    tmp_b = 0;
  }
  
  cout << ans << endl;
}