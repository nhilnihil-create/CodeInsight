#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  long int X; cin >> X;
  long int temp = 0;
  int i=1;
  while(temp<X){
    temp += i;
    i++;
  }
  cout << i-1 << "\n";
}
  