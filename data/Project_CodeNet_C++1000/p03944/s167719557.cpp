#include <iostream>

int main () {
	int w,h,n,x,y,a;
  	int finalX1, finalX2, finalY1, finalY2;
	int finalX, finalY;
  
  std::cin >> w >> h >> n;
 	finalX1 = finalX2 = finalY1 = finalY2 = 0;
 
  for(int i=0; i < n; i++) {
  	std::cin >> x >> y >> a;
    
    if(a == 1) {
      if(x > finalX1) {
	      finalX1 = x;
      }
    } else if (a == 2 ) {
      if(w-x > finalX2) {
	      finalX2 = w-x;
      }
    } else if (a == 3) {
      if(y > finalY1) {
      finalY1 = y;
      }
    } else {
      if(h-y > finalY2) {
	      finalY2 = h-y;
      }
    }
  }
  
  finalX = w - (finalX1 + finalX2);
  finalY = h - (finalY1 + finalY2);

 
  if (finalX <=0 || finalY <= 0) {
  	std::cout << 0 << std::endl;
  } else {
  	std::cout << finalX * finalY << std::endl;
  }
}