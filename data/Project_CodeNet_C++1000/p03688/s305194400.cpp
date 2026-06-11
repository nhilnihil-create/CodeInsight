#include <stdio.h>
#define N 100001

int a[N];

int read()
{
	char c;
	while((c = getchar()) < 48 || c > 57);
	int x = c - 48;
	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;
	return x;
}

int main()
{		
	int n, i, m = 0, t, c1 = 0, c2;
	
	n = read();
	for(i = 0; i < n; i++){
		a[i] = t = read();
		if(t > m) m = t;
	}
	for(i = 0; i < n; i++){
		t = a[i];
		if(t + 1 == m) c1++;
		else if(t != m){
			puts("No");
			return 0;
		}
	}
	if(!c1){
		if(m + 1 == n || m * 2 <= n) puts("Yes");
		else puts("No");
		return 0; 
	}
	c2 = n - c1;
	if(m <= c1 || c2 < (t = (m - c1) * 2) || t + c1 > n) puts("No");
	else puts("Yes");
	
			
	return 0;
}