#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int h, w;
  cin >> h >> w;
  char a[h+2][w+2];
  for(int i=0; i<h+2; ++i) for(int j=0; j<w+2; ++j) a[i][j] = '#';
  for(int i=1; i<h+1; ++i) for(int j=1; j<w+1; ++j) cin >> a[i][j];

  for(int i=0; i<h+2; ++i){
    for(int j=0; j<w+2; ++j){
      if(j==w+1){
        cout <<a[i][j] << endl;
      }
      else cout << a[i][j];
    }
  }
  return 0;
}