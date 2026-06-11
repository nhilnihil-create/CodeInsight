#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int sosu[1001];
int yakusu(int k){
	int re;
	for(int i = 1; i * i <= k; i++){
		re++;
	}
	return re;
}
void soinsu(int num){
	for(int i = 2; num != 1; i++){
		while(num % i == 0){
			num = num / i;
			sosu[i]++;
		}
	}
}
int main(void)
{
	int n; cin>>n;
	for(int i = 0; i <= n; i++) sosu[i] = 0;
	
	for(int i = 1; i <= n; i++){
		soinsu(i);
	}
	long long ans = 1;
	for(int i = 1; i <=n; i++){
		ans = ans * (sosu[i]+1) % mod;
	}
	
	/*
	for(int i = 1; i <= n; i++){
		cout<<"i = "<<i<<", sosu[i] = "<<sosu[i]<<endl;
	}
	*/
	
	cout<<ans<<endl;
	return 0;
}

