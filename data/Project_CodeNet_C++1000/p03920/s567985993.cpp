#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>









ll n;





void solve()
{
	cin>>n;
	for(ll i=1,j;;i++)
	{
		j=(i*(i+1))/2;
		if(j>=n)
		{
			for(ll k=1;k<=i;k++)
			{
				if(k==(j-n))continue;
				cout<<k<<"\n";
			}
			return;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}