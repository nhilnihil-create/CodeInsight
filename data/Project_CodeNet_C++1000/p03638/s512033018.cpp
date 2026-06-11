#include <bits/stdc++.h>
using namespace std;



int main() {
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a.at(i);
	}
	int grid[h][w];

	int x=0;
	int y=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<a.at(i); j++){
			grid[x][y] = i+1;
			if(x % 2 == 0){
				if(y == w-1){
					x++;
				}else{
					y++;
				}
			}else{
				if(y == 0){
					x++;
				}else{
					y--;
				}
			}
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}