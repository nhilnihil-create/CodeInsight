#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define INF (1<<31-1)
#define ll long long


int main(){

	int H, W, h, w;

	cin >> H >> W >> h >> w;

	if (W%w == 0 && H%h == 0){ cout << "No" << endl; return 0; }


	cout << "Yes" << endl;
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= W; j++){
			if (j%w != 0 || i%h != 0) cout << "1000 ";
			else cout << (-(h*w - 1) * 1000 - 1) << " ";
		}
		cout << endl;
	}


	return 0;
}
