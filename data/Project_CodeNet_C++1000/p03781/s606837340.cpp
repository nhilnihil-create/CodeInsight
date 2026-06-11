#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main()
{
	for(int i=1;;i++)
	{
		if(i*(i+1)/2>1e9)
		{
			break;
		}
		v.push_back(i*(i+1)/2);
	}
	scanf("%d",&n);
	printf("%d\n",lower_bound(v.begin(),v.end(),n)-v.begin()+1);
}