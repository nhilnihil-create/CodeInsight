#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;
const int maxn = 1e5 + 5;

LL fac[maxn];

void init(){
	fac[0] = 1;
	for(int i = 1;i <= 100000;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
}
int n;
int x[maxn];

int main(){
	init();
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;i++){
			scanf("%d",&x[i]);
		}
		int k = 0;
		LL ans = 1;
		for(int i = 1;i <= n;i++){
			if(x[i] >= 2 * k + 1){
				k++;
			}else{
				ans = ans * (k + 1) % mod;
			}
		}
		ans = ans * fac[k] % mod;
		cout << ans << endl;
	}
	return 0;
}
