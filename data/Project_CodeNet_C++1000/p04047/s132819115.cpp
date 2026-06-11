#include<bits/stdc++.h>
using namespace std;
const int MAXN = 210;

int n;
int arr[MAXN];
int ans;

bool cmp(const int &x, const int &y){return x < y;}

int main(){
	scanf("%d", &n); n <<= 1;
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + n + 1, cmp);
	for(int i = 1; i <= n; i += 2) ans += arr[i];
	printf("%d\n", ans);
	return 0;
}