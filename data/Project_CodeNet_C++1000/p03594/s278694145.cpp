#include<cstdio>
#include<vector>


using namespace std;
using vc=vector<char>;
using vvc=vector<vc>;


void fill(vvc&ans, int ox, int oy, int ax, int ay, int s, int c)
{
	int w=ans[0].size();
	int h=ans.size();

	for(int i=0;i<s;i++)
	{
		int y=oy+ay*i;
		if(y<0 || h<=y) continue;

		for(int j=0;j<s-i;j++)
		{
			int x=ox+ax*j;
			if(x<0 || w<=x) continue;

			ans[y][x]=c;
			x+=ax;
		}
	}
}


void fill_big(vvc&ans, int ox, int oy, int d, int c)
{
	fill(ans, ox-1, oy-1, -1, -1, d/2-1, c);
	fill(ans, ox  , oy-1,  1, -1, d/2-1, c);
	fill(ans, ox-1, oy  , -1,  1, d/2  , c);
	fill(ans, ox  , oy  ,  1,  1, d/2  , c);
}


void solve(vvc&ans, int d)
{
	int h=ans.size();
	int w=ans[0].size();

	if(d%2)
	{
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
			{
				ans[y][x]="RG"[(x+y)%2];
			}
		}
		return;
	}

	for(int iy=0;iy<h;iy++)
	{
		int y=iy*d;
		for(int ix=0;ix<w;ix++)
		{
			int x=ix*d;
			fill_big(ans, x    , y    , d, "RG"[(ix+iy)%2]);
			fill_big(ans, x+d/2, y+d/2, d, "BY"[(ix+iy)%2]);
			if(x-d/2-1>w) break;
		}
		if(y-d/2-1>h) break;
	}
}


int main(void)
{
	int h, w, d;

	while(scanf("%d%d%d", &h, &w, &d)==3)
	{
		vvc ans(h);

		for(auto&anse:ans) anse.assign(w, '#');

		solve(ans, d);

		for(int y=0;y<h;y++)
		{
			printf("%.*s\n", w, &ans[y][0]);
		}
	}

	return 0;
}
