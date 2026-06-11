#include<cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int n;
LL sum, a[N];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%I64d", &a[i]);
		sum += a[i];
	}
	int f1 = sum&1;
	int f2 = n&1;
	if(f1 == 1 && f2 == 1){
		int f = -1, c, win = 1, ff;
		LL g;
		while(f == -1){
			c = 0, ff = 0;
			for(int i = 0; i < n; i ++){
				if(a[i] & 1) c ++;
				if(a[i] == 1) ff = 1;
			}
			if(c == 1 && ff != 1){
				if(a[0] & 1) a[0] --;
				g = a[0];
				for(int i = 1; i < n; i ++){
					if(a[i] & 1){
						a[i] --;
					}
					g = __gcd(g, a[i]);
				}
				for(int i = 0; i < n; i ++){
					a[i] /= g;
				}
				sum --;
				sum /= g;
				if(sum & 1) win ^= 1;
				else f = win;
			}else{
				f = win;
			}
		}
		puts(f?"Second":"First");
		return 0;
	}
	puts(f1 == f2?"Second":"First");
}