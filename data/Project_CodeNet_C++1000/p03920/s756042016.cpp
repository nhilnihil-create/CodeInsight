#include <iostream>

using namespace std;

int main();
int point(int n);

int point(int n){
	int sum = 0, diff, i;
	int ans[100000];
	for(i = 1; sum <= n; i++){
		sum += i;
//		cout << i << endl;
		ans[i] = i;
	}
	i = i - 1;
	ans[i + 1] = 0;
	sum = sum - ans[i];
	ans[i] = 0;
	diff = n - sum;
//	cout << diff << endl;
	if(diff != 0){
		for(int j = 1; j <= diff; j++){
			ans[i - j] += 1;
		}
		sum = 0;
		for(i = 1; ans[i] != 0; i++){
			sum += ans[i];
			cout << ans[i] << endl;
		}
	}else{
		for(i = 1; ans[i] != 0; i++){
			cout << ans[i] << endl;
		}
	}
	return sum;
}

int main(){
	int n, ans;
	cin >> n;
	ans = point(n);
//	cout << ans << endl;
	return 0;
}