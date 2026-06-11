#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	int t;
	int s[N][3];
	int b[N];
	memset(b,0,sizeof(b));
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<t;i++){
		s[i][0]=a[i]+1;
		s[i][1]=a[i]-1;
		s[i][2]=a[i];
	}
	int k=0;
	for(int i=0;i<t;i++){
		b[s[i][0]]++;
		b[s[i][1]]++;
		b[s[i][2]]++;
	}
	sort(b,b+N,cmp);
	printf("%d\n",b[0]);
 } 