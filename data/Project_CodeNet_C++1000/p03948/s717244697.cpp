#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<utility>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int A[100100];
map<int,int> mp;
int main()
{
	int N,T,lst,x;
	cin>>N>>T;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		if(!i)
			x=A[i];
		else	x=min(lst,A[i-1]);
		mp[A[i]-x]++;
		lst=x;
	}
	map<int,int>::iterator it=mp.end();
	it--;
	cout<<it->second<<endl;
	return 0;
}