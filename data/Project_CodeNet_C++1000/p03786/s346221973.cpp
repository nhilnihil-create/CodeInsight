#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	int N;
	vector<int>A;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		A.push_back(a);
	}
	sort(A.begin(),A.end());
	ll c=0,r=0;
	for(int i=0;i<N-1;i++)
	{
		c+=A[i];
		if(c*2>=A[i+1])
		{
			r++;
		}
		else
		{
			r=0l;
		}
	}
	r++;//A[N-1]
	cout<<r<<endl;
}