#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
	
	int N;
	
	cin >> N;
	
	int upper[100001];
	
	for(int i = 0; i <= N; i++){
		upper[i] = 0;
	}
	
	int count = 0;
	
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		upper[N - count]++;
		if(num <= (i - count) * 2 && i != 0){
			count++;
		}
	}
	
	long long int ans = 1;
	int rest = 0;
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < upper[i]; j++){
			//cout << ans << " ";
			ans *= (i - rest);
			rest++;
			ans = ans % 1000000007;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}