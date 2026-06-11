#include <bits/stdc++.h>
using namespace std;

int main() {
  //はイパボリックうんちっち
  int N,T;
  cin >> N >> T;
  int min=1000000001,ben=0;//benはうんち!
  int sum=0;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    if(a<min)min=a;
    else if((a-min)==ben)sum++;
    else if((a-min)>ben){
      sum=1;
      ben=a-min;
    }
  }
  cout << sum;
}