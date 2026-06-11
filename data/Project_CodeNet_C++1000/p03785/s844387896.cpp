#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1000005];

void solve(long long n, long long c, long long k){
	sort(arr , arr + n);
	long long busPopulation = 1 , count = 1 , start = arr[0];

	for(long long i = 1; i < n; i++){
		if(arr[i] <= (start + k) && busPopulation < c){
			busPopulation++; 
		}
		else{
			count++;
			busPopulation = 1; // Create new bus
			start = arr[i];
		}
	}
	cout << count << endl; 
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	long long n, c, k;
	cin >> n >> c >> k; 
	// C - Bus capacity, K - Min Time
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
	}
	solve(n , c, k);
}