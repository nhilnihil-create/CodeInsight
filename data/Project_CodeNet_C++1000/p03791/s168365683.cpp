#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[100100];
long long frac[100100];
const int mo = 1e9 + 7;
int main(){
	//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	frac[0] = 1;
	for (int i = 1;i <= n; i++)
		frac[i] = (frac[i - 1] * i) % mo;
	int last = 0;
	long long ans = 1;
	long long cnt = n;
	for (int i = 1; i <= n; i++){
		if (a[i] < 2 * (i - last) - 1){
			ans = (ans * (i - last)) % mo;
			last++;
			cnt --;
		}
	}
	if (last != n) ans = (ans * frac[n - last]) % mo;
	//	cout << last << endl;
	cout << ans << endl;
	return 0;
}
