#include <bits/stdc++.h>
using namespace std;

/*

question is can we add some edges to get an connected graph
length n, k of the odd part
there will be (n-k)/2+k set after connected by a
we can at most add n/2 edges by b

so  n+k/2 <= n/2 + 1 so k<=2

if k=1 we always place the odd to the leftmost 
if k=2 1 leftmost 1 rightmost

we can generate b
a[0]+1, a[1] ... a[m-2], a[m-1]-1

*/

const int M=1e5+5;
const int MM=105;
int a[MM];


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1) cnt++;
	}
	if(m==1)
	{
		if(n==1)
			printf("1\n1\n1\n");
		else
			printf("%d\n2\n%d %d\n",n,1,n-1);
		return 0;
	}
	if(cnt>=3)
	{
		printf("Impossible\n");
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		if(a[i]&1)
		{
			swap(a[0],a[i]);
			break;
		}
	}
	for(int i=1;i<m;i++)
	{
		if(a[i]&1)
		{
			swap(a[i],a[m-1]);
			break;
		}
	}
	vector<int> vec;
	vec.push_back(a[0]+1);
	for(int i=1;i<m-1;i++)
		vec.push_back(a[i]);
	if(a[m-1]>1)
		vec.push_back(a[m-1]-1);
	for(int i=0;i<m;i++)
		printf("%d%c",a[i],i==m-1?'\n':' ');
	printf("%d\n",vec.size());
	m=vec.size();
	for(int i=0;i<m;i++)
		printf("%d%c",vec[i],i==m-1?'\n':' ');
	return 0;
}