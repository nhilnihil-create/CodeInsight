#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  int minimum=100,maximum=-100;
  int input;
  for(int i=0;i<N;i++){
    cin >> input;
    vec.at(i) = input;
    minimum = min(minimum,input);
    maximum = max(maximum,input);
  }
  int res = 2000000;
  int sum;
  for(int i=minimum;i<=maximum;i++){
    sum = 0;
    for(int x: vec){
      sum += (i-x)*(i-x);
    }
    res = min(res,sum);
  }
  cout << res << endl;
}