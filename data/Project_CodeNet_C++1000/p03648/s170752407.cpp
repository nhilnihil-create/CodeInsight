#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
	
	long long int K;
	
	cin >> K;
	
	long long int div = K / 50;
	long long int ret = K % 50;
	
	cout << "50" << endl;
	
	for(int i = 0; i < 50; i++){
		long long int output = div;
		if(i < ret){
			cout << output + 50 - (ret - 1) + 49;
		}else{
			cout << output - ret + 49;
		}
		if(i != 49){
			cout << " ";
		}
	}
	
	cout << endl;
	
	return 0;
}

