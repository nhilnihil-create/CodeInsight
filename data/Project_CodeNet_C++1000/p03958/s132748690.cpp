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
	int K,T;
	cin>>K>>T;
	priority_queue<int>A;
	for(int i=0;i<T;i++)
	{
		int a;
		cin>>a;
		A.push(a);
	}
	while(A.size()>1)
	{
		int f=A.top();A.pop();
		int s=A.top();A.pop();
		A.push(f-s);
	}
	cout<<max(A.top()-1,0)<<endl;
}