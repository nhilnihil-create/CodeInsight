#include <cstdio>
#include <algorithm>
#define N 302 
using namespace std;

int n , m , a[N][N] , p[N] , ans = 123456789;
int vis[N];
bool ban[N];

int main()
{
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; i ++)
	{
		p[i] = 1;
		for(int j = 1 ; j <= m ; j ++)
			scanf("%d" , &a[i][j]);
		vis[ a[i][p[i]] ]++;
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			while(ban[ a[j][p[j]] ] ) 
				vis[ a[j][p[j]] ]-- , vis[ a[j][++p[j]] ]++;

		int s = 1;
		for(int j = 1 ; j <= m ; j ++)
			if(vis[j] > vis[s]) s = j;
		ans = min(ans , vis[s]);
		ban[s] = 1;
	}
	printf("%d\n" , ans);
}