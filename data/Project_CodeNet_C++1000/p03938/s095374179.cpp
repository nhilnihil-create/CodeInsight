#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	ull n, i, mx;
	cin>>n;
	ull p[n+5], a[n+5], b[n+5], value[n+5];
	for(i=1; i<=n; i++){
		cin>>p[i];
		value[p[i]]=p[i]+i;
	}
	for(i=1; i<=n; i++){
		a[i]=value[i]+n*i;
	}
	mx=n+1;
	for(i=1; i<=n; i++){
		b[i]=mx*(mx-i);
	}
	for(i=1; i<=n; i++) cout<<a[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++) cout<<b[i]<<" ";
	return 0;
}
