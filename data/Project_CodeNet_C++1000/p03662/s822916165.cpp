#include<bits/stdc++.h>

using namespace std;

/********************************************************************************************************/

int n;
vector<int> v[100010];
int colr[100010];   //the color of each cell
int bl,wh;    //Fennec -> black , Snuke -> wh
int ok;

/***************************DFS()****************************/

void DFS(int x,int pre,int cl,int &tot)    //int &tot -> change tot while dfs()
{
	tot++;
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=pre&&colr[v[x][i]]!=-cl)DFS(v[x][i],x,cl,tot);
}

void dfs(int x,int pre,int s,int &ok)
{
	if(x==n)
	{
		ok=s;
		return;
	}
	
	for(int i=0;i<v[x].size();i++)
	{
		if(ok)break;
		if(v[x][i]!=pre)dfs(v[x][i],x,s+1,ok);
	}
	
	if(ok)
	{
		if(x!=1&&s<=ok/2)colr[x]=1;
		if(x!=n&&s>ok/2)colr[x]=-1;
	}
	
	return;
}

/******************************************main*************************************************/

int main()
{
	/*********cin*********/
	
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	/*****************clear***************/
	
	colr[1]=1;  //black
	colr[n]=-1;   //white
	//index from 1
	
	/***************do dfs in main()******************/
	
	dfs(1,-1000000007,0,ok);
	DFS(1,-1000000007,1,bl);
	DFS(n,-1000000007,-1,wh);
	
	/************************************************end****************************************/
	
	//judge who do more selections
	
	if(bl>wh)puts("Fennec");
	else puts("Snuke");
	
	return 0;
}