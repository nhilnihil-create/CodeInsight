#include <iostream>

using namespace std;
int main(void){
	int n;
	cin >> n;
	int nums[n];	
	int sum=0;
	for(int i=0; i<n;i++){
		cin >> nums[i];
		sum+=nums[i];
	}
	int med = sum/n;
	int ans = n*100000;
	for(int m=med-10; m <= med+10; m++){
	int res=0;
	for(int e : nums){
		int x = e - m;
		res+=x*x;
	}
	ans = min(ans, res);
	}
	cout << ans << endl;
}