#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[212345];
int cnt[212345];
int l[212345], r[212345];

int main() {
                                               

	stack <int> q;
	cin >> n;                                                                         
	for(int i = 1; i <= n; i++) {
	cin >> a[i]; 
	}

	for(int i = 1; i <= n; i++) {
		while(q.size() && a[q.top()] > a[i]) q.pop();
		if(q.empty()) l[i] = 1;
		else l[i] = q.top() + 1;
		q.push(i); 
	}
	while(q.size())q.pop();

	for(int i = n; i >= 1; i--) {
		while(q.size()&&a[q.top()]>a[i])q.pop();
		if(q.empty()) r[i]=n;
		else r[i]=q.top()-1;
		q.push(i);
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += (r[i] - i + 1) * 1LL * (i - l[i] + 1) * 1LL * a[i];
	cout << ans;	
}


