#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[212345];
int cnt[212345];

int main() {
                                               

	cin >> n;                                                                         
	for(int i = 1; i <= n; i++) {
	cin >> a[i]; 
	cnt[a[i]]++;
	}

	sort(a + 1, a + n + 1);
	if(a[1] * 2 < a[n]) return cout << "Impossible", 0;

	if(cnt[1]>1&&n>2)return cout << "Impossible", 0;
	if(a[n]>n-1) return cout << "Impossible", 0;
	if(a[n]==n-1 && cnt[a[n]]>2)return cout << "Impossible", 0;
	for(int i = n; i <= n; i++)
		if(a[i]!=1&&cnt[a[i]]<2)return cout << "Impossible", 0;

	for(int i = a[n]/2+1; i <= a[n]; i++)
		if(cnt[i]<=1)return cout << "Impossible", 0;
	for(int i = 1; i < (a[n]+1)/ 2; i++)
		if(cnt[i])return cout << "Impossible",0;
	if(a[n]%2)
		if(cnt[a[n]/2+1]!=2)return cout << "Impossible", 0;
	if(a[n]%2==0)
		if(cnt[a[n]/2]!=1)return cout << "Impossible",0;
	if(a[1] == a[n] && !(n==2&&a[1]==1)) return cout << "Impossible", 0;
	cout << "Possible";
	return 0;
}


