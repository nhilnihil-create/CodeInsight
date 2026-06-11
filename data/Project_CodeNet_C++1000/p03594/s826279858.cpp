#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
 
using namespace std;

int main(){
	
	string col = "RGBY";
	
	int H, W, d;
	cin >> H >> W >> d;
	
	if(d % 2 != 0){
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cout << col[(i + j) % 4];
			}
			cout << endl;
		}
		cout << endl;
		return 0;
	}
	
	string hoge[2];
	hoge[0] = "RG";
	hoge[1] = "BY";
	
	for(int i = 10000; i < 10000 + H; i++){
		for(int j = 0; j < W; j++){
			int dum = j;
			if((i + j) % 2 != 0){
				dum++;
			}
			cout << hoge[((i - dum) / d) % 2][((i + dum) / d) % 2];
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}