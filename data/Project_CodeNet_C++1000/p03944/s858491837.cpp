#include<bits/stdc++.h>
using namespace std;

int main() {
  int W,H,N;
  cin >> W >> H >> N;
  
  int max_x=W, max_y=H, min_x=0, min_y=0;
  
  for(int i=0; i<N; ++i) {
    int x,y,a;
    cin >> x >> y >> a;
    
    if(a == 1) {
      if (x > min_x){
                min_x = x;
            }
    }
    else if(a == 2) {
       if (x < max_x){
                max_x = x;
            }
    }
    else if(a == 3) {
       if (y > min_y){
                min_y = y;
            }
    }
    else if(a == 4) {
        if (y < max_y){
                max_y = y;
            }
    }
    }
    if (min_x < max_x && min_y < max_y){
        cout << (max_x - min_x)*(max_y - min_y) << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}