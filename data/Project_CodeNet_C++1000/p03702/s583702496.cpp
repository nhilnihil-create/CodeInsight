#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int arr[N];
int n, a, b;

bool valid2(long long trials, long long trial, long long cpy){
	return (trial * a + (trials - trial) * b) >= cpy;
}

bool valid(long long trials){
	long long needA = 0;
	for(int i = 0; i < n; ++i){
		long long cpy = arr[i], low = 0, high = trials, mid;
		if(trials * a < cpy)
			return 0;
		while(low < high){
			mid  = low + (high - low) / 2;
			if(valid2(trials, mid, cpy)){
				high = mid;
			}
			else{
				low = mid+1;
			}
		}
		needA += high;
	}
	return needA <= trials;
}

int main() {
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	int low = 0, high = 1e9+2, mid;
	while(low < high){
		mid  = low + (high - low) / 2;
		if(valid(mid)){
			high = mid;
		}
		else{
			low = mid+1;
		}
	}
	cout << high;
	return 0;
}
