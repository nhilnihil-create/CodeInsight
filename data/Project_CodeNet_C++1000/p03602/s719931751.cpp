#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int d[303][303];
bool d_n[303][303];

int main(void){
  int n;
  cin >> n;

  long long ans = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> d[i][j];
    }
  }
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){

        if(d[i][j] > d[i][k] + d[k][j]){
          cout << "-1" << endl;
          return 0;
        }

        if(d[i][j] == d[i][k] + d[k][j] && d[i][k] > 0 && d[k][j] > 0){
          d_n[i][j] = true;
        }

      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){

      if(d_n[i][j] == false){
        ans += d[i][j];
      }

    }
  }
  cout << ans << endl;
  return 0;
}