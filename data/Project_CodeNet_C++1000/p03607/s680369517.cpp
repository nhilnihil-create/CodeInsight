#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int main()
{
    long int n,i,j,k,a=1,count=0;
	scanf("%ld",&n);
	
	vector<long int> v;
	
	for(i=0;i<n;i++)
	{
		scanf("%ld",&j);
		v.push_back(j);		
	}
	
	sort(v.begin(),v.end());
	
	for(i=0;i<v.size();i=j)
	{
		
		for(j=i+1;j<v.size();j++)	
		{
			if(v[i] == v[j]) a++;
			else break;
		}
		if(a&1) count++;
		a=1;
	}
	
	printf("%ld",count);
}