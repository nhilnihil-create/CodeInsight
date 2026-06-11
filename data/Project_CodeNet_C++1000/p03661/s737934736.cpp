#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	int N;
	cin >> N;
	long nums[N];
	long first_sum = 0, second_sum = 0;
	for(int i = 0; i < N; i++){
		cin >> nums[i];
		second_sum += nums[i];
	}
	long ans = 1e18;
	for(int i = 0; i < N - 1; i++){
		first_sum += nums[i];
		second_sum -= nums[i];
		ans = min(ans, abs(first_sum - second_sum));
	}
	cout << ans << endl;
}