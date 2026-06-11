#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
  cin >> n;
  int res = 0;
  while(n > 1){
    n/=2;
    res++;
  }
  cout << (1<<res) << endl;
  return 0;
}
