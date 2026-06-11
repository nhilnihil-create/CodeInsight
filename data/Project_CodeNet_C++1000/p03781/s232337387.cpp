#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
queue<pii> q;
//map<int,bool> mp; 
int main()
{
	int x,wz,ti,i,tot;
	scanf("%d",&x);
	tot=0;
	for(i=1;;i++)
	{
		tot+=i;
		if(tot>=x)break;
	}
	printf("%d",i);
	return 0;
}