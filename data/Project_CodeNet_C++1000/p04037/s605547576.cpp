#include <bits/stdc++.h>

using namespace std;
int n,dat[100005];
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&dat[i]);
	sort(dat+1,dat+n+1,cmp);
	
	int row=1,col=0;
	while(dat[row+1]>=row+1) row++;
	while(dat[row+col+1]>=row) col++;
	
	printf(!((dat[row]-row)&1)&&!(col&1)?"Second":"First");
	return 0;
}