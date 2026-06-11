//Created Time:2019年12月02日 星期一 21时16分28秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100005

using namespace std;

long long ans;
int a[N][2];
long long sum1[N], sum2[N];

int main(){
	int n; scanf("%d", &n);
	scanf("%d", &a[1][0]); sum1[1] = sum2[1] = a[1][0];
	for(int i = 1; i < n; ++i){
		int x = 0; bool flag = false; char ch = getchar();
		for(; !isdigit(ch); ch = getchar()) flag |= (ch == '-');
		for(; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
		a[i + 1][0] = x; a[i + 1][1] = flag; 
		sum1[i + 1] = sum1[i] + (flag ? -x : x);
		sum2[i + 1] = sum2[i] + x;
	}
	ans = sum1[n];
	for(int i = 1; i <= n; ++i)
		if(a[i][1]){
			int pos = i + 1; long long tmp = 0;
			while(!a[pos][1] && pos <= n) tmp += a[pos++][0];
			ans = max(ans, sum1[i] - tmp + sum2[n] - sum2[pos - 1]);
			i = pos - 1;
		}
	cout << ans << endl;
	return 0;
}