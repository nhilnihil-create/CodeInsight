#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum=0;
  int ai=1;
  while(sum<N){
    sum+=ai;
    ai++;
  }
  int del=sum-N;
  for(int i=1;i<ai;i++){
    if(i!=del)cout << i << endl;
  }
}

