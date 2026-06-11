#include<bits/stdc++.h>
#define maxn 100005
#define Mod 1000000007
#define Val(x) ((((long long)x) % Mod + Mod) % Mod)
using namespace std;
int x[maxn],y[maxn];
int arr[maxn],brr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> x[i];
		if(i > 1)	arr[i-1] = x[i] - x[i-1];
	}
	for(int i=1;i<=m;i++) {
		cin >> y[i];
		if(i > 1)	brr[i-1] = y[i] - y[i-1];
	}
	n--;	m--;
	int sum1 = 0 , sum2 = 0;
	for(int i=1;i<=n;i++)
		arr[i] = Val(arr[i] + arr[i-1]) , sum1 = Val(sum1 + arr[i]);
	for(int i=1;i<=m;i++)
		brr[i] = Val(brr[i] + brr[i-1]) , sum2 = Val(sum2 + brr[i]);
	
	int a = 0 , b = 0;
	for(int i=1;i<=n;i++) {
		a = Val(a + sum1);
		sum1 = Val(sum1 - (long long)(arr[i] - arr[i-1]) * (n - i + 1));
	} 
	for(int i=1;i<=m;i++) {
		b = Val(b + sum2);
		sum2 = Val(sum2 - (long long)(brr[i] - brr[i-1]) * (m - i + 1));
	}
	cout << Val(a * b) << endl;
	return 0;
}
