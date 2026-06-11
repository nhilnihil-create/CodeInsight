#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int sum=0;
  int i=1;
  while(true){
    sum+=i;
    if(sum>=X)break;
    i++;
  }
  cout << i;
}


