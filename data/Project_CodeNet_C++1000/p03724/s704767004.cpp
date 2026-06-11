#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;

int ko[100010];
int main(){
	int n,m;cin>>n>>m;
	string ans="YES";
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		ko[a]++,ko[b]++;
	}
	for(int i=0;i<n;i++)
	{
		if(ko[i]%2==1)
		{
			ans="NO";
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}