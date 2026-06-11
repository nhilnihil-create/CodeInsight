#include<cstdio>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include <cstring>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#include <random>
#define inf  1000000000
#define mod  1073741824
#pragma GCC optimization ("O3")
using namespace std;
const long long int N = 6999999;
#define all(x) begin(x),end(x)
long long int dp[51][2700][51];
long long int ways(int n,long long int s,int c,vector <int> &v,int k)
{
	if(n < 0)
		return 0;
	if(n == 0)
	{
		if (c == 0)
			return 0;
		int rem = s % c;
		if (rem != 0)
			return 0;
		int avg = s/c;
		if (avg == k){
			return 1;
		}
	}
	if(dp[n][s][c] != -1)
		return dp[n][s][c];
	long long int dnpick = ways(n-1,s,c,v,k);
	long long int pick = ways(n-1,s+v[n],c+1,v,k);
	long long int t = pick + dnpick;
	dp[n][s][c] = t;
	return t;
}
long long int way(int n,int k,vector <int>&v1)
{
	vector<int> v;
	v.push_back(-1);
	for (int i = 0; i < n; ++i)
	{
		v.push_back(v1[i]);
	}
	memset(dp,-1,sizeof(dp));
	long long int ans = ways(n,0,0,v,k);
	return ans;
}
int main()
{
   
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  	int n,k;
  	cin >> n >> k;
  	vector <int> v1(n);
  	for (int i = 0; i < n; ++i)
  	{
  		cin >> v1[i];
  	}
  	cout << way(n,k,v1);
  	// for (int i = 1; i < 4; ++i)
  	// {
  	// 	for (int j = 1; j < 3; ++j)
  	// 	{
  	// 		/* code */
  	// 	}
  	// }	
  	return 0;
}	