#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N = 1e5 + 5;
 
int a[N] , n;
 
bool cmp(int x , int y) {
	return x > y;
}
 
int main(void) {
	scanf("%d" , &n); for(int i = 1;i <= n;i ++) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1 , cmp);
	int res = 0 , cur = -1;
	for(int i = 1;i <= n + 1;i ++) if(a[i] < i) {
		cur = i - 1; break;
	}
	res = 1;
	for(int j = cur + 1;a[j] == cur;j ++) res ^= 1;
	res &= (a[cur] - cur + 1) & 1;
	if(res)
	puts("Second");
	else puts("First");
}