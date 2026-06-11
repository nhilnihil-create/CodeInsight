#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i=1;
  for(;i*(i+1)/2<n;i++);
  int t=i*(i+1)/2-n;
  for(int j=1;j<=i;j++){
    if(j!=t)cout << j << endl;
  }
  return 0;
}