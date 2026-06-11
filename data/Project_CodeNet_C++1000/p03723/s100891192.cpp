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
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;


int main(){
	LL a,b,c;cin>>a>>b>>c;
	LL ans=0;
	if(a==b && b==c && a%2==0)
	{
		cout<<-1<<"\n";
		return 0;
	}
	while(a%2==0 && b%2==0 && c%2==0)
	{
		LL sum=a+b+c;
		a=(sum-a)/2;	
		b=(sum-b)/2;
		c=(sum-c)/2;
		ans++;
	}
	cout<<ans<<"\n";
	
	return 0;
}