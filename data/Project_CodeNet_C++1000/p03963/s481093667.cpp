#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  
  long long num=k;
  for(int i=1; i<n; i++){
    num = num *(k-1);
  }
  
  cout << num << endl;
}
