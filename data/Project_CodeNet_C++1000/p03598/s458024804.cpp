#include <bits/stdc++.h>
using namespace std;

int main() {
   
  int n, k;
  cin >> n >> k;
  int x;
  int a = 0;
  
  for (int i = 0; i < n; i++){
    cin >> x;
    if (k-x >= x-0){
       a += x * 2;
       continue;
       }
    if (k-x < x-0){
       a += (k - x) * 2;
       continue;
       }
    
  }
  
  cout << a << endl;
}

