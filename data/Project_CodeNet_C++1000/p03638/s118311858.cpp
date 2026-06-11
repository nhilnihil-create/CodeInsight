#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int>P;

int main()
{
	int H,W,N;
	cin>>H>>W>>N;
	vector<int>cnt(N,0);
	vector<vector<int>>G;
	for(int i=0;i<H;i++)
	{
		vector<int>r(W,0);
		G.push_back(r);
	}
	for(int i=0;i<N;i++)
	{
		cin>>cnt[i];
	}
	int np=0;
	int npc=0;
	for(int i=0;i<H;i++)
	{ 
		if(i%2)
		{
			for(int j=0;j<W;j++)
			{
				G[i][j]=np;
				npc++;
				if(npc==cnt[np])
				{
					np++;
					npc=0;
				}
			}
		}
		else
		{
			for(int j=W-1;j>=0;j--)
			{
				G[i][j]=np;
				npc++;
				if(npc==cnt[np])
				{
					np++;
					npc=0;
				}
			}
		}
	}
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			cout<<G[i][j]+1<<(j==W-1?'\n':' ');
		}
}