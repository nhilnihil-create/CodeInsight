#include <bits/stdc++.h>
using namespace std;

int main(){
  int rate[9];
  for(int i = 0; i < 9; i++){
    rate[i] = 0;
  }
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    if(a/400 < 9){
       rate[a/400]++;
    }
    else{
      rate[8]++;
    }
  }
  int min_num = 0;
  for(int i = 0; i < 8; i++){
    if(rate[i] != 0){
      min_num++;
    }
  }
  int max_num = min_num + rate[8];
  if(min_num == 0){
    min_num = 1;
  }
  cout << min_num <<' ' << max_num;
}
