#include <cstdio>

using namespace std;

const int N = 2e5 + 500;

int n, x, p[N], c = 1;

int main(){
	scanf("%d%d", &n, &x);
	if(x == 1 || x == 2 * n - 1){
		printf("No\n");
		return 0;
	}
	if(x <= n){
		p[n - 1] = x;
		p[n] =     x - 1;
		p[n - 2] = x + 1;
		p[n + 1] = x + 2;
	}
	else{
		p[n - 1] = x;
		p[n] =     x + 1;
		p[n - 2] = x - 1;
		p[n + 1] = x - 2;
	}
	printf("Yes\n");
	for(int i = 0;i < 2 * n - 1;i++){
		if(!p[i]){
			if((x <= n && c == x - 1))
				c = x + 3;
			if((x > n && c == x - 2))
				c = x + 2;
			p[i] = c++;
		}
		printf("%d\n", p[i]);
	}
}