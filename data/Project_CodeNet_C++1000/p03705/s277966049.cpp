#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	ull n, a, b;
	cin>>n>>a>>b;
	if(n==1)
		a==b ? cout<<1 : cout<<0;
	else if(n==2)
		a==b ? cout<<0 : cout<<1;
	else if(a>b)
		cout<<0; 
	else{
		cout<<((n-1)*b+a)-((n-1)*a+b)+1;
	}
	return 0;
}