#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define int long long

const int N = 51;

const int INF = 1e16;

const int inf = INF / 51;

int n , m , k , a[51] , b[51];

void read() {
	scanf("%lld" , &k);
}

int times = 0 , ans = 0;

signed main() {
	read();
	if(k <= 49) {
		puts("50");
		cout<<50 * k<<" ";
		for(int i = 2;i <= 50;i ++) cout<<0<<" ";
		return 0;
	}
	n = 50;
	cout<<50<<endl;
	for(int j = 1;j <= n; j ++) a[j] =n -1 - k;
	for(int i = 1;i <=n;i ++) {
		if(a[i] < 0) {
			int p = -  a[i];
			p /=(n+1);
			if((n+1) * p != -a[i]) {
				p++;
			}
			a[i] += p * (n + 1);
			k -= p;
		}
	}
	int cal =  k / n;
	for(int i = 1;i <=n;i ++) {
		a[i] += cal*(n+1);
	}
	k %= n;
	for(int i = 1;i <=n;i ++) {
		if(!k) break;
		a[i] +=n+1;
		k--;
	}
	for(int i = 1;i <= n ;i ++) cout<<a[i]<<" ";
}