#include <iostream>
using namespace std;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if(H%h<1 && W%w<1) cout << "No" << endl;
	else{
	    cout << "Yes" << endl;
	    int T=((H/h)*(W/w))/(W*(H%h)+H*(W%w)-(H%h)*(W%w))+1;
	    for(int i=1; i<=H; ++i){
	        for(int j=1; j<=W; ++j){
	            if(i%h<1 && j%w<1) cout << -T*(h*w-1)-1;
	            else cout << T;
	            if(j<W) cout << ' ';
	            else cout << endl;
	        }
	    }
	}
	return 0;
}
