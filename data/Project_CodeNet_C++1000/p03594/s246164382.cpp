#include <bits/stdc++.h>
using namespace std;
char C(int i){
	if(i % 4 == 0) return 'R'; 
	if(i % 4 == 1) return 'Y'; 
	if(i % 4 == 2) return 'G'; 
	if(i % 4 == 3) return 'B'; 
}
int main(){
	int H, W, D; cin >> H >> W >> D; 
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			int a = (i + j) % (2 * D); 
			int b = (i - j + W) % (2 * D); 
			int c = (a >= D ? 1 : 0) + (b >= D ? 2 : 0); 
			cout << C(c); 
		}
		cout << endl; 
	}	
}