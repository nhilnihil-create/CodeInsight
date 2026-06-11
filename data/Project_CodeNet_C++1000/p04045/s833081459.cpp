#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,k;
  cin >> n >> k;
  int ara[10] = {0};
  for(int i = 0;i<k;i++){
    int x;
    cin >> x;
    ara[x] = 1;
  }
  for(;true;n++){
    int temp = n;
    int cnt = 0;
    while(temp>0){
      int d = temp%10;
      temp/=10;
      if(ara[d] != 0){
        cnt++;
        break;
      }
    }
    if(cnt == 0){
      break;
    }
  }
  cout << n << endl;
  return 0;
}
