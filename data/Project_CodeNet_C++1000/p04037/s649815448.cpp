#include <bits/stdc++.h>

using namespace std;

int seq[100050];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n; ++ i) scanf("%d",&seq[i]);
	sort(seq + 1,seq + 1 + n,cmp);
	int ps = 0;
	for(int i = 1;i <= n; ++ i)
	{
		if(seq[i] < i)
		{
			ps = i - 1;
			break;
		}
	}
	if(!ps) ps = n;
	long long d1 = seq[ps] - ps;
	int vl = ps; ps ++;
	long long d2 = 0;
	while(seq[ps] >= vl && ps <= n) d2 ++,ps ++;
	if((d2 & 1) || (d1 & 1)) printf("First\n");
	else printf("Second\n");
}