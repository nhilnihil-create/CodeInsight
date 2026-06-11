//**************************
//*** writer  :  Alex Hu **
//************************

#include<bits/stdc++.h>

using namespace std;

#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=1e5+10;

int input[maxn][3];
int ma[maxn],an[maxn];
int bfs[maxn];
vi e[maxn];

void go(int in[])
{
	int x=in[0]-1;
	int dd=in[1];
	int v=in[2];
	if (dd<=ma[x]) return;
	ma[x]=dd;
	bfs[0]=x;
	int rr=1;
	rept(i,0,rr)
	{
		int x=bfs[i];
		if (!an[x]) an[x]=v;
		if (!ma[x]) continue;
		rept(j,0,e[x].size())
		{
			int y=e[x][j];
			int nd=ma[x]-1;
			if (nd>ma[y])
			{
				ma[y]=nd;
				bfs[rr++]=y;
			}
		}
	}
}

int n,m,q;

int main()
{
	cin>>n>>m;
	rept(i,0,m)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	cin>>q;
	rept(i,0,q)
	{
		rept(j,0,3)
		{
			cin>>input[i][j];
		}
	}
	CLEAN(ma,-1);
	for (int i=q-1;i>=0;i--) go(input[i]);
	rept(i,0,n) cout<<an[i]<<endl;
	return 0;
}