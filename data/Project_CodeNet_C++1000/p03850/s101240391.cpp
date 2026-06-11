#include <algorithm>
#include <assert.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

const int MX = 100005;

template <typename T> void read(T &x)
{
	x = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) && c!='-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(isdigit(c)) x = x*10+c-'0', c = getchar();
	if(f) x = -x;
}

template <typename T> T max(const T &x, const T &y, const T &z)
{
	return max(max(x, y), z);
}

int n;
int opr[MX], seq[MX];
ll f[MX][3];

int main()
{
	read(n);
	opr[1] = +1;
	for(int i=1; i<=n; i++)
	{
		read(seq[i]);
		if(i != n)
		{
			char c = getchar();
			while(c!='+' && c!='-') c = getchar();
			if(c == '+') opr[i+1] = +1;
			else opr[i+1] = -1;
		}
	}
	f[0][1] = f[0][2] = -1e18;
	for(int i=1; i<=n; i++)
	{
		if(opr[i] == +1)
		{
			f[i][0] = max(f[i-1][0]+seq[i], f[i-1][1]+seq[i], f[i-1][2] + seq[i]);
			f[i][1] = max(f[i-1][1]-seq[i], f[i-1][2]-seq[i]);
			f[i][2] = f[i-1][2]+seq[i];
		}
		else
		{
			f[i][0] = -1e18;
			f[i][1] = max(f[i-1][0]-seq[i], f[i-1][1]-seq[i], f[i-1][2]-seq[i]);
			f[i][2] = max(f[i-1][1]+seq[i], f[i-1][2]+seq[i]);
		}
		//cout<<i<<" : "<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
	}
	printf("%lld\n", max(f[n][0], f[n][1], f[n][2]));
	return 0;
}
