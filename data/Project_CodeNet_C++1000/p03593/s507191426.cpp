#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;
typedef long long ll;

int main()
{
	int H, W;
	string a[101];
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		cin >> a[i];
	}
	int four = (H/2) * (W/2);
	int two, one;
	if(H%2 == 0 && W%2 == 1){
		two = H/2;
	}else if(H%2 == 1 && W%2 == 0){
		two = W/2;
	}else{
		two = 0;
	}
	if(H%2 == 1 && W%2 == 1){
		one = 1;
	}else{
		one = 0;
	}
	
	int letterCount[26];
	fill(letterCount, letterCount+26, 0);
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			letterCount[((int)a[i][j]-97)]++;
		}
	}
	
	int four_ = 0;
	int two_ = 0;
	int one_ = 0;
	for(int i = 0; i < 26; i++){
		four_ += letterCount[i]/4;
		two_ += (letterCount[i] % 4) /2;
		one_ += letterCount[i] % 2;
	}
	
	bool isYes = true;
	if(four_ < four){
		isYes = false;
	}
	else{
		four -= four_;
		if(two_ < four*2 + two){
			isYes = false;
		}
		else if(one_ != one){
			isYes = false;
		}
	}
	
	cout << (isYes ? "Yes" : "No") << endl;
	
	return 0;
}