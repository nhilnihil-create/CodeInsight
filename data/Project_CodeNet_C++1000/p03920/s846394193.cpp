#include<cstdio>

using namespace std;

int main(){
	int n, cnt = 1, x = 0;
	scanf("%d", &n);
	while(1){
		x += cnt;
		if(n <= x) break;
		cnt++;
	}
	int t = x - n;
	for(int i = 1; i <= cnt; i++){
		if(i != t){
			printf("%d\n", i);
		}
	}
	return 0;
}