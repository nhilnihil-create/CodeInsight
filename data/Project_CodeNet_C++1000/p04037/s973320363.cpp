#include <cstdio>
#include <algorithm>
const int maxn = 1e5 + 5;
using namespace std;
int a[maxn], n;
bool cmp(const int &x, const int &y){
	return x > y;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		if (i + 1 > a[i + 1]){
			int ans = 0, j = i;
			while (a[j + 1] == i) ++j;
			ans = ((a[i] - i) & 1) | ((j - i) & 1); 
			if (ans) puts("First");
			else puts("Second");
			return 0;
		}
	}
	return 0;
} 