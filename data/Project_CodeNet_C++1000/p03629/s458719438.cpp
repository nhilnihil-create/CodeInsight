#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

vector< vector<int> >v(26) ;
int n ;

string s ;

int dp[MAX] ;

int solve(int idx)
{
	if(idx == n)
		return 0 ;
	int &ret = dp[idx] ;
	if(ret != -1)
		return ret ;
	ret = 1e9 ;
	for(int i = 0 ; i < 26 ; ++i)
	{
		int idx2 = upper_bound(v[i].begin() , v[i].end() , idx) - v[i].begin() ;
		ret = min(ret , solve(v[i][idx2]) + 1) ;
	}
	return ret ;
}

void build(int idx)
{
	if(idx == n)
		return ;
	for(int i = 0 ; i < 26 ; ++i)
	{
		int idx2 = upper_bound(v[i].begin() , v[i].end() , idx) - v[i].begin() ;
		if(solve(idx) == solve(v[i][idx2]) + 1)
		{
			cout<<(char)(i+'a') ;
			build(v[i][idx2]) ;
			break ;
		}
	}
}

int main()
{
	memset(dp , -1 , sizeof(dp)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>s ;
	s = "#" + s ;
	n = s.size() ;
	for(int i = 1 ; i < n ; ++i)
		v[s[i]-'a'].push_back(i) ;
	for(int i = 0 ; i < 26 ; ++i)
		v[i].push_back(n) ;
	build(0) ;
	return 0 ;
}		