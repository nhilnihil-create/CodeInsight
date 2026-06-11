#include<iostream>
#define N 100000
#define LOG 20
using namespace std;
int h[N+1];
int farthest[N+1][LOG+1]; //farthest[i][j] -> the farthest you can go from i in 2^j days
int lg[N+1];
int maximum_distance(int i, int d) //in d days, how far can you get?
{
	int j = i;
	while(d > 0)
	{
		j = farthest[j][lg[d]];
		d -= (1<<lg[d]);
	}
	return j;
}
int b_search(int a, int b)
{
	int L = 1;
	int R = 100000;
	while(R-L>1)
	{
		int M = (L+R)/2;
		if(maximum_distance(a,M) >= b)
			R = M;
		else
			L = M;
	}
	if(maximum_distance(a,L) >= b)
		return L;
	else
		return R;
}
int first_dude(int i, int dist, int n)
{
	int L = i; 
	int R = n;
	while(R-L>1)
	{
		int M = (L+R)/2;
		if(h[M]-h[i] <= dist)
			L = M;
		else
			R = M;
	}
	if(h[R]-h[i] <= dist)
		return R;
	else
		return L;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for(int x = 0; x <= LOG; x++)
		for(int n = (1<<x); n <= N && n < (1<<(x+1)); n++)
			lg[n] = x;
		
	int n, L;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	cin >> L;
	
	for(int i = 1; i <= n; i++)
		farthest[i][0] = first_dude(i,L,n);
		
	for(int x = 1; x <= LOG; x++)
		for(int i = 1; i <= n; i++)
			farthest[i][x] = farthest[farthest[i][x-1]][x-1];
	
	int Q; cin >> Q;
	while(Q--)
	{
		int a, b; cin >> a >> b;
		cout<<b_search(min(a,b),max(a,b))<<'\n';
	}
	return 0;
}