#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vc=vector<char>;
using vvc=vector<vc>;


struct f_t
{
	int n;
	int x, y, f;
	bool operator<(const f_t&rhs) const
	{
		if(n!=rhs.n) return n>rhs.n;
		if(x!=rhs.x) return x>rhs.x;
		return y>rhs.y;
	}
};


bool cmp(f_t*a, f_t*b)
{
	if(a->n!=b->n) return a->n>b->n;
	if(a->x!=b->x) return a->x<b->x;
	return a->y<b->y;
}


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
	char s[]="RYGBxyz";

	if(d%2)
	{
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
			{
				ans[y][x]=s[(x+y)%2];
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
			fill_big(ans, x, y, d, "RG"[(ix+iy)%2]);
			if(x-d/2-1>w) break;
		}
		if(y-d/2-1>h) break;
	}

	for(int iy=0;iy<=h;iy++)
	{
		int y=iy*d+d/2;
		for(int ix=0;ix<w;ix++)
		{
			int x=ix*d+d/2;
			fill_big(ans, x, y, d, "BY"[(ix+iy)%2]);
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
		vvi f(h);
		vvc ans(h);

		for(int y=0;y<h;y++)
		{
			f[y].assign(w, 0x0F);
			ans[y].assign(w, '#');
		}

		solve(ans, d);

		for(int y=0;y<h;y++)
		{
			printf("%.*s\n", w, &ans[y][0]);
		}
	}

	return 0;
}
