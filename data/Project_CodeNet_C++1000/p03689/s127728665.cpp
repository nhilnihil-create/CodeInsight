#include <iostream>
#include <vector>

using namespace std;

int main(){
	int H, W, h, w;
	while(cin >> H >> W >> h >> w){
		vector<vector<int>> mtx(H, vector<int>(W, 0));
		if(h==1 && w==1){
			cout << "No" << endl;
			continue;
		}
		long long sum = 0;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(i%h == h-1 && j%w == w-1){
					mtx[i][j] = -1000000000;
				} else if(i%h == 0 && j%w == 0){
					mtx[i][j] = 999999999 - (h*w-2);
				} else {
					mtx[i][j] = 1;
				}
				sum += mtx[i][j];
			}
		}
		if(sum > 0){
			cout << "Yes" << endl;
			for(int i=0;i<H;i++){
				cout << mtx[i][0];
				for(int j=1;j<W;j++) cout << " " << mtx[i][j];
				cout << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
}
