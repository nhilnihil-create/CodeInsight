#include<iostream>
#include<vector>

using namespace std;
bool f[100010];

int main(){
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i != a[i] - 1) f[i] = true;
	}
	for(int i = 0; i < n; i++){
		if(!f[i]){
			ans++;
			f[i] = true;
			f[i + 1] = true;
		}
	}
	cout << ans << endl;
	return 0;
}
