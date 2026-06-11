#include <iostream>

using namespace std;
int main(void){
	int w, h, n;
	cin >> w >> h >> n;
	int grid[100][100] = { 0 };
	while(n--){
		int x, y, a;
		cin >> x >> y >> a;
		for(int j=0; j<h; j++){
			for(int i=0; i<w; i++){
				switch(a){
					case 1:
						grid[j][i] = i<x || grid[j][i];
						break;
					case 2:
						grid[j][i] = i>=x || grid[j][i];
						break;
					case 3:
						grid[j][i] = j<y || grid[j][i];
						break;
					case 4:
						grid[j][i] = j>=y || grid[j][i];
						break;
				}
			}
		}
	}
	int sum = 0;
	for(int j=h-1; j>=0; j--){
		for(int i=0; i<w; i++){
			sum += !grid[j][i];
		}
	}
	cout << sum << endl;
}