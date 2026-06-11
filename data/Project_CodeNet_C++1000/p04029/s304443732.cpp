#include <bits/stdc++.h>
using namespace std;

int ame(int x){
  if(x == 0)
    return x;
  
  else
    return x+ame(x-1);
}
  

int main() {
  int n,total=0;
  
  cin >> n;
  
  total = ame(n);
  
  cout << total;
  
}