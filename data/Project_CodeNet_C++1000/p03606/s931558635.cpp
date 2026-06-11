#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main(){
  int n;
  cin >> n;
  int human[n][n];
  rep(i,n){
      cin >> human[i][0] >> human[i][1];
  }
  
  int sum = 0;
  for(int i=0; i < n; i++){
    sum += (human[i][1]-human[i][0]) + 1;
  }
  
  cout << sum << endl;
}