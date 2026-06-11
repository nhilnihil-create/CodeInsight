#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  int free_cnt = 0;
  const long long mod = 1e9 + 7;
  long long ans = 1;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(free_cnt * 2 + 1 <= tmp){
      free_cnt++;
    }else{
      ans *= (free_cnt + 1);
      ans %= mod;
    }
  }

  for(int j = 1; j <= free_cnt; j++){
    ans *= j;
    ans %= mod;
  }
  cout << ans << endl;
}
