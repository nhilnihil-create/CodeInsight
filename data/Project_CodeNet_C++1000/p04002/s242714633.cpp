#include<iostream>
#include<set>
#include<cstring>
using namespace std;
typedef long long LL;
set<pair<int,int> > the_blacks;
LL freq[10];
LL H, W, n; 
void update(int x, int y, int as)
{
	for(int i = max(1,x-2); i <= min(H-2,(LL)x); i++)
		for(int j = max(1,y-2); j <= min(W-2,(LL)y); j++)
		{
			int ctr = 0;
			for(int di = 0; di <= 2; di++)
				for(int dj = 0; dj <= 2; dj++)
					ctr += the_blacks.count({i+di,j+dj});
			freq[ctr] += as;
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> n;
	memset(freq,0,sizeof freq);
	freq[0] = (H-2)*(W-2);

	while(n--)
	{
		int a, b; cin >> a >> b;
		update(a,b,-1);
		the_blacks.insert({a,b});
		update(a,b,1);
	}

	for(int i = 0; i <= 9; i++)
		cout<<freq[i]<<endl;


	return 0;
}