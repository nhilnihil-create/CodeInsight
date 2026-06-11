#include <iostream>

using namespace std;

int H, W, h, w;

int main(void)
{
	cin >> H >> W >> h >> w;
	
	if(H % h == 0 && W % w == 0){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	int pval = W/w * H/h * 2;
	int nval = -pval * (w * h - 1) - 1;
	for(int y = 1; y <= H; y++){
		for(int x = 1; x <= W; x++){
			if(x % w == 0 && y % h == 0) cout << nval;
			else cout << pval;
			if(x != W) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}