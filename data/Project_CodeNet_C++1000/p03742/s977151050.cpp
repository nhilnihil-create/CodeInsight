#include <bits/stdc++.h>

using namespace std ;

/*const int MAX = 1000 ;
int dp[MAX][MAX][2] ;

int solve(int x , int y , int turn)
{
	if(x <= 1 && y <= 1)
		return (!turn) ;
	int &ret = dp[x][y][turn] ;
	if(ret != -1)
		return ret ;
	ret = !turn ;
	for(int i = 1 ; ; ++i)
	{
		if(2*i > x && 2*i > y)
			break ;
		if(2*i <= x)
		{
			int a = solve(x-2*i , y+i , !turn) ;
			if(a == turn)
				ret = turn ;
		}
		if(2 * i <= y)
		{
			int a = solve(x+i , y-2*i , !turn) ;
			if(a == turn)
				ret = turn ;
		}
	}
	return ret ;
}*/

int main()
{
	//memset(dp , -1 , sizeof(dp)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	long long x , y ;
	cin>>x>>y ;
	if(max(x , y) >= min(x , y)+2)
		return cout<<"Alice\n" , 0 ;
	return cout<<"Brown\n" , 0 ;
} 