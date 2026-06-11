#include <iostream>
#include <cmath>
using namespace std;

long long x[100001];
long long y[100001];
int mod = 1e9+7;
int main(){
	int n,m;
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> x[i];
	}
	for(int j = 1;j<=m;j++){
		cin >> y[j];
	}
	long long xt = 0,yt = 0;
	for(int i = 1;i<=n;i++){
		xt+=(x[i]*(i-1));
		xt%=mod;
		xt-=(x[i]*(n-i));
		xt%=mod;
	}
	for(int i = 1;i<=m;i++){
		yt+=(y[i]*(i-1));
		yt%=mod;
		yt-=(y[i]*(m-i));
		yt%=mod;
	}
	cout << (xt*yt)%mod;
}