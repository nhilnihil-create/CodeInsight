#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <math.h>
using namespace std;



int main(void){
  int W,H,N;
  cin >> W >> H >> N;
  int bx=0,by = 0;
  int tx=W , ty=H; 
  for(int i =0; i < N ; i++){
        int x,y,a;

        cin >> x >> y >> a;
        switch (a)
        {
        case 1:
          if(bx < x){
            bx = x;
          }
          break;
        case 3:
          if(by < y){
            by = y;
          }
          break;
        case 2:
          if(x < tx){
            tx = x;
          }
          break;
        case 4:
          if(y < ty){
            ty = y;
          }
         break;
      }
  }
  cout << max(tx-bx,0)*max(ty-by,0) << endl;
  return 0;

}