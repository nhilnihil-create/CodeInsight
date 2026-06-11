#include <cstdio>

using namespace std;

const int N = 1e5 + 500;

int n, a[N], b[N], p[N];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", p + i);	
		a[p[i]] = 2 * i;
		b[p[i]] = n + 1 - i;
	}
	for(int i = 1;i <= n;i++)
		a[i] = (n + 1) * i;
	for(int i = 1;i <= n;i++)
		b[p[i]] = (n + 1) * (n + 1) - (a[p[i]] + n + 1 - i);
	for(int i = 1;i <= n;i++)
		printf("%d ", a[i]); 
	printf("\n");
	for(int i = 1;i <= n;i++)
		printf("%d ", b[i]); 
	printf("\n");
	
}