#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 5e5 + 5;
typedef long long ll; 
using namespace std;

int n;
ll ans, tmp; 
char s[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int x, i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
		{
			x = 1;
			for(int k = 1; k < i - 1; k++) x = x * 2; 
			for(int k = j + 1; k < n; k++) x = x * 2; 
			tmp = s[i] - '0'; 
			for(int k = i + 1; k <= j; k++) tmp = tmp * 10 + s[k] - '0'; 
			ans += tmp * x; 
		}
	cout<<ans<<endl; 
	return 0; 
}
