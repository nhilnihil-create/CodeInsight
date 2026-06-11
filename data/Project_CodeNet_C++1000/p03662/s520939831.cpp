/*  include  */
#include <bits/stdc++.h>

/*  using namespace  */
using namespace std;

/*  local var  */
int a,b,n;		//input
int ans = 0;		//output
vector<int> g[100005];  //graph
int distance_Fennec[100005]; //Distance from ふぇねええええええええええええええええええええええええっく
int distance_Sunuke[100005]; //Distance from Snuke

/*  define  */
#define loop(i,j) for(int i = 0; i < j; i++)
#define scan1(d) scanf("%d",&d);
#define scan2(a,b) scanf("%d %d",&a,&b);

/*  typedef  */
//None

/*  distance checker  */
void calc_distance(int r, int f, int d, int dist[]) {
	dist[r] = d;
	for(int x = 0; x < g[r].size(); x++)
		if (g[r][x] != f) calc_distance(g[r][x], r, d + 1, dist);
			
}

/*  main program  */
int main()
{
	scan1(n);

	for(int i = 0; i < n - 1; i++) {
		scan2(a,b);
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	calc_distance(0  ,-1,0,distance_Fennec);
	calc_distance(n-1,-1,0,distance_Sunuke);

	for(int i = 0;i < n; i++){
		if(distance_Fennec[i] <= distance_Sunuke[i]) ans++;
		else ans--;
	}

	printf("%s\n",(ans > 0) ? "Fennec" : "Snuke");
}
