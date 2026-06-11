#include<bits/stdc++.h>
using namespace std;
int Next[200200][30];
bool Vis[200200];
int Prev[200200];
int main()
{
	string S;
	cin>>S;
	int N=S.length();
	S="\n"+S;
	for(int i=0;i<26;i++)
		Next[N][i]=-1;
	for(int i=N-1;i>=0;i--)
		for(int j=0;j<26;j++)
			if(S[i+1]-'a'==j)
				Next[i][j]=i+1;
			else	Next[i][j]=Next[i+1][j];
	queue<int> Q;
	//bfs可能超时(@TwT@)但我只会这个了
	//Plus:啊。bfs不会超时 
	Q.push(0);
	Vis[0]=true;
	Prev[0]=-1;
	while(!Q.empty())
	{
		int X=Q.front();
		Q.pop();
		for(int i=0;i<26;i++)
			if(Next[X][i]==-1)
			{
				//Yeah竟然这么快就写输出了
				string Ans;
				Ans+=('a'+i);
				while(X!=-1)
				{
					Ans+=S[X];
					X=Prev[X];
				}
				reverse(Ans.begin(),Ans.end());
				cout<<Ans.substr(1)<<endl;
				return 0;
			}
			else if(!Vis[Next[X][i]])
			{
				int Y=Next[X][i];
				Vis[Y]=true;
				Prev[Y]=X;
				Q.push(Y);
			}
	}
	return 0;
}
//frqnvhydscshfcgdemurlfrutcpzhopfotpifgepnqjxupnskapziurswqazdwnwbgdhyktfyhqqxpoidfhjdakoxraiedxskywuepzfniuyskxiyjpjlxuqnfgmnjcvtlpnclfkpervxmdbvrbrdn