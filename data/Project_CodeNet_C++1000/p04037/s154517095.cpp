//Created Time:2020年01月05日 星期日 18时54分37秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100005

using namespace std;

int n;
int a[N];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + 1 + n, cmp);
	int pos = 1;
	while(a[pos + 1] >= pos + 1) ++pos;
	int p = pos;
	while(a[p + 1] == pos) ++p;
	if((a[pos] - pos) & 1 || (p - pos) & 1) puts("First");
	else puts("Second");
    return 0;
}
