#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
int64_t Q , H , S ,D; cin >> Q >> H >> S >> D;
int64_t N; cin >> N;
int64_t count = 0;
if(min(8*Q,min(4*H,2*S))> D){
	if(N != 1){
		count = D * (N / 2);
		if(N % 2 == 1){
			count += min(4*Q,min(2*H,S));
		}

	}
	else{
		count = min(4*Q,min(2*H,S))*N;
	}
}
else{
	count = min(4*Q,min(2*H,S)) * N;
}

cout << count << endl;
}