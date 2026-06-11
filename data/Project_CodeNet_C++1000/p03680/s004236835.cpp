#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t , ans = 0;
void slove()
{
	int n;cin >> n;
	vector<int> f(n + 1);
	for(int i = 1;i <= n;i ++)
		cin >> f[i];
	vector<bool> vis(n + 1 , 0);
	vis[1] = 1;bool flag = false;
	int s = 1;
	while(f[s] != 2)
	{
		//printf("%d %d\n",s , f[s]);
		if(vis[f[s]])
		{
			flag = 1;
			break;
		}
		s = f[s];vis[s] = 1;ans++;
	}
	cout << (flag ? -1 : ans + 1) << endl;
}
int main()
{
	SIS;
	slove();
}