#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int i=0;
  while(i*(i+1)/2<X){
    i++;
  }
  cout << i << endl;
}