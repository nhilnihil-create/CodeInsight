#include<bits/stdc++.h>
using namespace std;
int h,w,n,cou;
set<pair<int,int> > s;
long long grid[12];

int main()
{
	int a,i,j;
	int r,c;
	
	scanf("%d %d %d",&h,&w,&n);
	int ha = h-2,wa = w-2;
	grid[0] = ((long long)ha * (long long)wa );
	for(a=1;a<=n;a++)
	{
		scanf("%d %d",&r,&c);
		if(r+2<=h && c-2>=1) //downleft
		{
			cou = 0;
			for(i=r;i<=r+2;i++)
				for(j=c-2;j<=c;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r-2>=1 && c-2>=1) //topleft
		{
			cou = 0;
			for(i=r-2;i<=r;i++)
				for(j=c-2;j<=c;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r-2>=1 && c+2<=w) //topright
		{
			cou = 0;
			for(i=r-2;i<=r;i++)
				for(j=c;j<=c+2;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r+2<=h && c+2<=w) //downright
		{
			cou = 0;
			for(i=r;i<=r+2;i++)
				for(j=c;j<=c+2;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(c-2>=1 && r-1>=1 && r+1<=h) //left
		{
			cou = 0;
			for(i=r-1;i<=r+1;i++)
				for(j=c-2;j<=c;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r-2>=1 && c-1>=1 && c+1<=w) //top
		{
			cou = 0;
			for(i=r-2;i<=r;i++)
				for(j=c-1;j<=c+1;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(c+2<=w && r-1>=1 && r+1<=h) //right
		{
			cou = 0;
			for(i=r-1;i<=r+1;i++)
				for(j=c;j<=c+2;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r+2<=h && c-1>=1 && c+1<=w) //down
		{
			cou = 0;
			for(i=r;i<=r+2;i++)
				for(j=c-1;j<=c+1;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		if(r-1>=1 && c-1>=1 && r+1<=h && c+1<=w) //center
		{
			cou = 0;
			for(i=r-1;i<=r+1;i++)
				for(j=c-1;j<=c+1;j++)
					if( s.count({i,j}) ) cou++;
			grid[cou]--; grid[cou+1]++;
		}
		
		s.insert({r,c});
	}
	
	for(i=0;i<=9;i++)
	{
		printf("%lld\n",grid[i]);
	}
}