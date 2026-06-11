#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int main()
{
	int N;
	ll tt=0,res=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		if(t==0)
		{
			res+=tt/2;
			tt=0;
		}
		else
			tt+=t;
	}
	res+=tt/2;
	cout<<res<<endl;
}