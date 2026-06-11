#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int count = 0;
  for(int i = 1;i <= n;i++){
    count += i;
    if(count >= n){
      for(int j = 1;j <= i;j++){
        if(count - n != j && j != i){
          cout << j << " ";
        }else if(j == i){
          cout << j;
        }
      }
      break;
    }
  }
}