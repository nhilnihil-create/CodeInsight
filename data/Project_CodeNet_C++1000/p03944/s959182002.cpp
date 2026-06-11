#include <iostream>
using namespace std;
int main(void){
	int x0=0, y0=0, xmax, ymax, n;
	cin >> xmax >> ymax >> n;
	while(n--){
		int x, y, a;
		cin >> x >> y >> a;
		switch(a){
			case 1:
				if(x>x0)x0 = x;
				break;
			case 2:
				if(x<xmax)xmax = x;
				break;
			case 3:
				if(y>y0)y0 = y;
				break;
			case 4:
			if(y<ymax)ymax = y;
				break;
		}
	}
	if(xmax<=x0 || ymax<=y0){
		cout << 0 << endl;
	}else cout << (xmax-x0)*(ymax-y0) << endl;
}