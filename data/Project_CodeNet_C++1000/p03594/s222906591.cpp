#include <bits/stdc++.h>
using namespace std;
int N;
char a[610][610];
int H, W, d;
bool isin(int i, int j){
  if( 0 <= i && i < 610 &&
      0 <= j && j < 610 )
    return true;
  return false;
}
void f(int h, int w, char c){
  int dd = (d-1) / 2;
  for(int k = -dd; k <= dd; k++){
    for(int i = h + abs(k); i <= h + d - 1 - abs(k); i++){
      if( isin(i, w+k) )
	a[i][w+k] = c;
    }
  }
}
void f2(int h, int w, char c){
  int dd = d / 2;
  for(int dh = 0; dh < dd; dh++){
    for(int ww = w + dh; ww <= w + d - 2 - dh; ww++){
      if( isin( h + dh, ww ) ){
	a[h + dh][ ww ] = c;
      }
      if( isin( h - 1 - dh, ww ) ){
	a[h - 1 - dh][ ww ] = c;
      }
    }
  }
}

int main(){
  cin >> H >> W >> d;
  for(int i = 0; i <= 610 + d; i += d){
    for(int j = 0; j <= 610 + d; j += d){
      if( (i/d + j/d) % 2 == 0 ){
	f( i, j, 'R');
      }else{
	f( i, j, 'G');
      }
    }
  }
    for(int i = 0; i <= 610 + d; i += d){
      for(int j = 1; j <= 610 + d; j += d){
	if( (i/d + (j-1)/d) % 2 == 0 ){
	  f2( i, j, 'B');
	}else{
	  f2( i, j, 'Y');
	}
      }
    }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if( a[i][j] == 0 )
	cout << ".";
      else
	cout << a[i][j];
    }
    cout << endl;
  }
}
