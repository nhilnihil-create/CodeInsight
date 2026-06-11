#include <stdio.h>
#include <string>
int n,m, d;
int main() {
scanf("%d%d%d", &n, &m, &d);
for (int i = 1; i <= n; i++,puts(""))
for (int j = 1; j <= m; j++) {
int t1 = ((i - j + m) / d) & 1, t2 = ((i + j)/d)&1;
printf("%c","RGBY"[t1*2+t2]);
}
return 0;
}