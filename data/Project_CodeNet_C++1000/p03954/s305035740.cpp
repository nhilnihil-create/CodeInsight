#include<bits/stdc++.h>
using namespace std;

int n,a[200010];

template <typename T> inline void read(T &a) {
	a = 0;char c = getchar();int f = 1;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)) {a = (a<<3) + (a<<1) + (c ^ 48); c = getchar();}
	a*=f;
}

inline bool check (int k) {
	if((a[n-1] <= k && a[n] <= k) || (a[n] <= k && a[n+1] <=k)) 
		return true;
	if((a[n-1] > k && a[n] > k) || (a[n] > k && a[n+1] > k)) 
		return false;
	for(int i = 1;i < n-1 ;++i) {
		if((a[n + i] <= k && a[n + i + 1] <= k) || (a[n - i] <= k && a[n - i -1] <=k))
			return true;
		if((a[n + i] > k && a[n + i +1] > k) || (a[n - i] > k && a[n - i -1] > k))
			return false;
	}
	return a[1] <= k;
}

int main () {
	read(n);
	for(int i=1;i<(n << 1);++i)
		read(a[i]);
	int l = 1, r =(n << 1) - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}