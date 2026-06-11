#include <cstdio>
#include <algorithm>

#define __FILE(x)\
	freopen(#x".in" ,"r" ,stdin);\
	freopen(#x".out" ,"w" ,stdout)
const int MX = 200000 + 232;
int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9')
		x = x * 10 + k - '0' ,k = getchar();
	return x;
}

int a[MX] ,b[MX] ,n;

int check(int lim){
	int flg = 1;
	for(int i = 1 ; i < 2 * n ; i += 2){
		flg = flg && a[i] >= lim;
	}
	// 为 10101....10101
	if(flg) return flg;

	if(a[n] >= lim){
		// 一旦有两个连续的就可以传上去
		for(int i = 0 ; i < n ; i += 2){
			if(a[n + i] >= lim && a[n - i] >= lim){
				if(a[n + i + 1] >= lim || a[n - i - 1] >= lim){
					return 1;
				}
			}
			else break;
		}
	}
	if(a[n + 1] >= lim && a[n - 1] >= lim){
		for(int i = 0 ; n + 2 + i < 2 * n ; i += 2){
			if(a[n + 1 + i] >= lim && a[n - 1 - i] >= lim){
				if(a[n + 2 + i] >= lim || a[n - 2 - i] >= lim){
					return 1;
				}
			}
			else break;
		}
	}
	return false;
}

int main(){
	n = read();
	for(int i = 1 ; i < 2 * n ; ++i)
		a[i] = b[i] = read();
	if(n == 1){
		printf("%d\n" ,a[1]);
		return 0;
	}
	std::sort(b + 1 ,b + 2 * n);
	b[0] = -114514 ,b[2 * n] = 2147483647;
	int l = 1 ,r = 2 * n ,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(b[mid])){
			l = mid + 1;
			//fprintf(stderr ,"%d is ok.\n" ,b[mid]);
		}
		else{
			r = mid - 1;
			//fprintf(stderr ,"%d is not ok.\n" ,b[mid]);
		}
	}printf("%d\n" ,b[l - 1]);
	return 0;
}