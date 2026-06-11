#include <bits/stdc++.h>

using namespace std ;

int n ; 
const int MAXN = 100010 ; 

int gcd(int a, int b) {return b ? gcd(b, a % b) : a ;} 

int a[MAXN] ; 

bool check() { 
		int cnt[2] = {0, 0} ; 
		for (int i = 1; i <= n; i ++) cnt[a[i] & 1] ++ ; 
		int w = cnt[0] & 1 ; 
		if (w) return 1 ; 
		if (cnt[1] > 1) return 0 ;
	    bool flag = 0 ; 	
		for (int i = 1; i <= n; i ++) { 
				if ((a[i] & 1) && a[i] > 1) {
						a[i] -- ;
					    flag = 1 ; 	
						break ; 
				}
		}
		if (!flag) return 0 ; 
		int d = 0 ; 
		for (int i = 1; i <= n; i ++) d = gcd(a[i], d) ; 
		for (int i = 1; i <= n; i ++) a[i] /= d ; 
		return check() ^ 1 ; 
}
int main() { 
		scanf("%d", &n) ; 
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]) ; 
		if (n == 1) { 
				puts("Second") ; 
				return 0 ; 
		}
		puts(check() ? "First" : "Second") ; 
}

