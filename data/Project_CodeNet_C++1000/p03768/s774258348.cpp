#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000+10;
int color[maxn][15];
int v[maxn],d[maxn],c[maxn];
vector <int> node[maxn];
void paint(int v1, int d1, int c1)
{    
    if(d1==-1)  return;    
	if(color[v1][d1] ) return;    
	color[v1][d1] = c1;    
	for(int i =0;i<node[v1].size();i++)        
	paint(node[v1][i], d1-1, c1);
}int main()
{    
    ios::sync_with_stdio(0);    
	memset(color, 0, sizeof color);    
	int N, M;    
	cin >> N >>M;    
	for(int i=1;i<=M;i++){        
	int a, b;        
	cin >> a >> b;        
	node[a].push_back(b);        
	node[b].push_back(a);    
	}    ///自己指向自己， 才能够自己跑到color[i][0]    
	for(int i=1;i<=N;i++)        
	node[i].push_back(i);    
	int q;    
	cin >> q;    
	for(int i=1;i<=q;i++)        
	cin >> v[i] >> d[i] >> c[i];    
	for(int i=q;i>=1;i--)        
	paint(v[i], d[i], c[i]);    
	for(int i=1;i<=N;i++)        
	cout<<color[i][0]<<endl;    
	return 0;
}
