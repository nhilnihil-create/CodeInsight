#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int sum =0;
  
  for(int i = 0; i < N; i++){
    int l,n;
    cin >> l >> n;
    
    int m = n-l+1;
    
    sum+=m;
  }

  cout << sum << endl;


}