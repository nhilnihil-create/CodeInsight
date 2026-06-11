#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	if(n % 2 == 0){
		bool flag1 = true;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0){
				if(a.at(i) != i + 1){
					flag1 = false;
					break;
				}
			}
			else{
				if(a.at(i) != i){
					flag1 = false;
					break;
				}
			}
		}
		if(flag1){
			// cout << "b.size() = " << b.size() << endl;
			long long ans1 = 1;
			for(int i = 0; i < n / 2; i++){
				ans1 %= mod;
				ans1 *= 2;
			}
			cout << ans1 % mod << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	else{
		bool flag2 = true;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0){
				if(a.at(i) != i){
					flag2 = false;
					break;
				}
			}
			else{
				if(a.at(i) != i + 1){
					flag2 = false;
					break;
				}
			}
		}
		if(flag2){
			// cout << "b.size() = " << b.size() << endl;
			long long ans2 = 1;
			for(int i = 0; i < (n - 1) / 2; i++){
				ans2 %= mod;
				ans2 *= 2;
			}
			cout << ans2 % mod << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	// cout << "a: ";
	// for(int i = 0; i < (int)a.size(); i++){
	// 	cout << a.at(i) << " ";
	// }
	// cout << endl << "b: ";
	// for(int i = 0; i < (int)b.size(); i++){
	// 	cout << b.at(i) << " ";
	// }
	// cout << endl;
	// cout << b.size() << endl;
	return 0;
}