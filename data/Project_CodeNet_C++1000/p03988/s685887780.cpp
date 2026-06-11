#include<cstdio>
using namespace std;

const int MAXN = 110;

int a[MAXN], c[MAXN];

int main(){
	int N, d = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i){
		scanf("%d", &a[i]), ++c[a[i]];
		if (a[i] > d)
			d = a[i];
	}
	bool flag = 0;
	if (d & 1){
		if (c[d + 1 >> 1] != 2)
			flag = 1;
		for (int i = d + 1 >> 1; i <= d; ++i)
			if (c[i] < 2){
				flag = 1;
				break;
			}
		for (int i = d >> 1; i >= 1; --i)
			if (c[i]){
				flag = 1;
				break;
			}
	}
	else {
		if (c[d >> 1] != 1)
			flag = 1;
		for (int i = (d >> 1) + 1; i <= d; ++i)
			if (c[i] < 2){
				flag = 1;
				break;
			}
		for (int i = (d >> 1) - 1; i >= 1; --i)
			if (c[i]){
				flag = 1;
				break;
			}
	}
	if (flag)
		printf("Impossible");
	else
		printf("Possible");
	return 0;
}
