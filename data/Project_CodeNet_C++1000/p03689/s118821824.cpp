#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int H, W, h, w; 
	cin >> H >> W >> h >> w; 
	long long int A[510][510] = {}; 
	long long int sum = 0; 
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(i % h == 0 && j % w == 0){A[i][j] = (long long) 999999999;}
			if(i % h == h - 1 && j % w == w - 1){A[i][j] = (long long) (-1000000000);}
			sum += A[i][j]; 
		}
	}
	if(sum <= 0){cout << "No" << endl;}
	else{
        cout << "Yes" << endl; 
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cout << A[i][j] << " "; 
			}
			cout << endl; 
		}	
	}
}