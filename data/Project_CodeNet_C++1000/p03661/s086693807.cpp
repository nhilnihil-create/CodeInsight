#include<cstdio>
const int MAX = 2e5 + 5;
int a[MAX];
int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		sum += a[i];
	}
	
	long long left,right,temp;
	
	left = sum - a[n - 1];
	right = a[n - 1];
	long long min = left > right ? left - right : right - left;
	left = 0;
	for (int i = 0; i < n-2; i++) {
		left += a[i];
		right = sum - left;
		temp = left > right ? left - right : right - left;
		if (temp < min)
			 min=temp;
	}
	printf("%d\n", min);
	return 0;
}