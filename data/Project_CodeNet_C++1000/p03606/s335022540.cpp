#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<vector<int>> num(N,vector<int>(2));
    for(int i = 0;i < N;i++){
      for(int j = 0;j < 2;j++){
        cin >> num[i][j];
      }
    }
  int sum = 0;
   for(int i = 0;i < N;i++){
        sum += num[i][1] - num[i][0] + 1;
   }
  
  cout << sum << endl;
  
  
   
}