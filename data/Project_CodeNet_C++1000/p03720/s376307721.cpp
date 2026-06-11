#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  vector<vector<int>> data(b,vector<int>(2));
  for(int i = 0;i < b;i++){
    for(int j = 0;j < 2;j++){
      cin >> data[i][j];
    }
  }
  for(int k = 0;k < a;k++){
    int count = 0;
      for(int i = 0;i < b;i++){
        for(int j = 0;j < 2;j++){
          if(data[i][j] == k+1){
            count++;
          }
        }
      }
    cout << count << endl;
  }
  
}
       