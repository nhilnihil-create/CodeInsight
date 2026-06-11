#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;

int n;
LL a[N * 3];
LL b[N * 3], c[N * 3];

priority_queue< LL, vector<LL>, greater<LL> > q;
priority_queue< LL, vector<LL>, less<LL> > p;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n * 3; i++)	
		scanf("%d",&a[i]);
	for (int i = 1;i <= n; i++){
		q.push(a[i]);
		b[i] = b[i - 1] + a[i];
	}
	for (int i = n * 3;i >= n * 2 + 1; i--){
		p.push(a[i]);
		c[i] = c[i + 1] + a[i];
	}
	for (int i = n + 1;i <= n * 2; i++){
		if (a[i] > q.top()){
			q.push(a[i]);
			b[i] = b[i - 1] + a[i];
		}
		else b[i] = b[i - 1];
		if (q.size() > n){
			b[i] -= q.top();
			q.pop();
		}
	}
	for (int i = n * 2;i >= n + 1; i--){
		if (a[i] < p.top()){
			p.push(a[i]);
			c[i] = c[i + 1] + a[i];
		}
		else c[i] = c[i + 1];
		if (p.size() > n){
			c[i] -= p.top();
			p.pop();
		}
	}
	LL ans = -90000000000000;
	for (int i = n;i <= n * 2; i++){
		if (b[i] - c[i + 1] > ans)
			ans = b[i] - c[i + 1];
	}
	printf("%lld\n",ans);
	return 0;
}