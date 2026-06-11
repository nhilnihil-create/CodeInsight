#include <iostream>
#include <vector>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h+1,vector<char>(w+1));
  int i,j;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      cin >> a[i][j];
    }
  }
  vector<vector<char>> b(2*h+1,vector<char>(w+1));
  for(i=1;i<=2*h;i++){
    for(j=1;j<=w;j++){
      b[i][j] = a[(i+1)/2][j];
    }
  }
  for(i=1;i<=2*h;i++){
    for(j=1;j<=w;j++){
      cout << b[i][j];
    }
    cout << "\n";
  }
  return 0;
}