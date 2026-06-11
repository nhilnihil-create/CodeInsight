#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int x,y,a[7] = {1,3,5,7,8,10,12},b[4] = {4,6,9,11};
  cin >> x >> y;
  if (x == 2 || y == 2){
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < 7; i++){
    if (x == a[i]){
      for (int j = 0; j < 7; j++){
        if (y == a[j]){
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < 4; i++){
    if (x == b[i]){
      for (int j = 0; j < 4; j++){
        if (y == b[j]){
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}