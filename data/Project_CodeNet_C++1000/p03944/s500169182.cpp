#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(void){
  int W, H, N;
  cin >> W >> H >> N;

  int x, y, a; 
  int xl = 0;
  int xr = W;
  int yl = 0;
  int yh = H;

  for(int i=0; i<N; i++){
	cin >> x >> y >> a;
     	if(a==1) xl = max(xl, x);
     	if(a==2) xr = min(xr, x);
     	if(a==3) yl = max(yl, y);
     	if(a==4) yh = min(yh, y);
  }//for

  int wide   = max(0, xr - xl);
  int height = max(0, yh - yl);
  cout << wide * height << "\n";
}//main
