//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
//#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll; 
typedef unsigned int ull; 
//typedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
struct ed{
	int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v, int w){
	e[tot].to = v, e[tot].w = w, e[tot].nxt = head[u], head[u] = tot++;
}

int a[N], n, op = 1, x, y;
int  main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n + 1; i++)
	{
		if (i > a[i])
		{
			x = a[i - 1] - i + 1;
			int j = 0;
			for (; a[i + j] == i - 1; j++)
				y++;
			if ((x & 1) | (y & 1))
				printf("First\n");
			else
				printf("Second\n");
			break;
		}
	}
	
}