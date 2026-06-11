#include<cstdio>
#include<cstdlib>
#include<cstring>
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
vector<int>B,NB;

int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		B.push_back(t);
	}
	sort(B.begin(),B.end());
	unique(B.begin(),B.end());
	B.erase(std::unique(B.begin(), B.end()), B.end());
	int mp=B[0];
	for(;;)
	{
		NB=B;
		for(int i=1;i<B.size();i++)
		{
			
			NB.push_back(B[i]-B[i-1]);
		}
		B=NB;
		sort(B.begin(),B.end());
		unique(B.begin(),B.end());
		B.erase(std::unique(B.begin(), B.end()), B.end());
		if(mp==B[0])break;
		mp=B[0];
	}
	for(int i=B.size()-1;i>=0;i--)
	{
		if(B[i]<K)break;
		int x=B[i]-K;

		for(int j=i;j>=0;j--)
		{
			if(x>B[j])
			{
				x%=B[j];
			}
		}
		if(x==0)
		{
			cout<<"POSSIBLE"<<endl;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;

}