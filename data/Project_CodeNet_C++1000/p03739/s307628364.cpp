#include<bits/stdc++.h>

using namespace std;

long long res, standard, n, a[100000], sum;
long long ans = 1000000000000000LL;

int get_sign(int x){
	if(0 < x) return 1;
	else if(x < 0) return -1;
	else return 0;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];

	res = 0, standard = 1, sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i];
		if(standard != get_sign(sum)){
			int add = abs(sum) + 1;
			res += add;
			if(sum > 0) sum -= add;
			else if(sum < 0) sum += add;
			else sum = standard;
		}
		standard *= (-1);
	}
	ans = min(ans, res);

	res = 0, standard = -1, sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i];
		if(standard != get_sign(sum)){
			int add = abs(sum) + 1;
			res += add;
			if(sum > 0) sum -= add;
			else if(sum < 0) sum += add;
			else sum = standard;
		}
		standard *= (-1);
	}
	ans = min(ans, res);

	cout << ans << endl;
}