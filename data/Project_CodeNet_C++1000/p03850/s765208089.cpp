#include <iostream>
#include <string>
#define int long long
#define INF 1e+18
using namespace std;

string op[100010];

signed main(){
	int n,a[100010],imos[100010] = {},sum = 0,ma = -INF;
	cin >> n;
	for(int i = 0;i < n;i++){
		if(i) cin >> op[i];
		else op[i] = "+";
		cin >> a[i];
		imos[i + 1] = imos[i] + a[i];
	}
	for(int i = 0;i < n;i++){
		if(op[i] == "-"){
			int pos = i + 1,tmp = -a[i];
			while(op[pos] == "+" && pos < n) tmp -= a[pos++];
			ma = max(ma,sum + tmp + imos[n] - imos[pos]);
			sum -= a[i];
		}else sum += a[i];
	}
	cout << max(ma,sum) << endl;
	return 0;
}