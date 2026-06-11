#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int max = 1;
  int max_cnt = 0;
  int num;
  int cnt;
  for (int i = 1; i < N + 1; i++)
  {
    num = i;
    cnt = 0;
    while (num > 0){
      if (num % 2 == 0){
        cnt += 1;
        num /= 2;
      }
      else
      {
        break;
      }
      
    }
    if (cnt > max_cnt){
      max_cnt = cnt;
      max = i;
    }
  }
  cout << max << endl;
}