#include<iostream>
#include<algorithm>
using namespace std;
int A,B,C,D,E,F;
bool dp[3001][3001];
main()
{
	cin>>A>>B>>C>>D>>E>>F;
	dp[0][0]=true;
	int ansa=100*A,ansb=0;
	for(int i=0;i<=F;i++)for(int j=0;j<=F;j++)
	{
		if(!dp[i][j])continue;
		if(i+100*A<=F)dp[i+100*A][j]=true;
		if(i+100*B<=F)dp[i+100*B][j]=true;
		if(i+C<=F&&j+C<=F)dp[i+C][j+C]=true;
		if(i+D<=F&&j+D<=F)dp[i+D][j+D]=true;
		if((i-j)/100*E<j)continue;
		if(ansb*100*i<j*100*ansa)ansa=i,ansb=j;
	}
	cout<<ansa<<" "<<ansb<<endl;
}
