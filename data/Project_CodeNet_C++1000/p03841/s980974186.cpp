#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 505;

int n, p[N * N], x[N], k[N], prior[N];

bool cmp(int A,int B){
	return x[A] < x[B];
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", x + i), x[i]--;
		prior[i - 1] = i;
	}
	sort(prior, prior + n, cmp);
	for(int i = 0;i < n * n;i++){
		int mora = 0;
		for(int j = 1;j <= n;j++){
			if(i == x[j])
				mora = j;
		}
		if(mora){
			k[mora]++; p[i] = mora;
			continue;
		}
		int naso = 0;
		for(int jj = 0;jj < n;jj++){
			int j = prior[jj];
			if(k[j] < j - 1){
				k[j]++; naso = j;
				break;
			}
		}
		if(!naso){
			for(int j = 1;j <= n;j++){
				if(k[j] != j - 1 && k[j] < n){
					k[j]++; naso = j;
					break;
				}
			}
		}
		if(!naso){
			printf("No\n");
			return 0;
		}
		p[i] = naso;
	}
	printf("Yes\n");
	for(int i = 0;i < n * n;i++)
		printf("%d ", p[i]);
	printf("\n");
}