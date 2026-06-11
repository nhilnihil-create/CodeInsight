#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int cmp(int x,int y)
{
	return x>y;
}
int main(){
	int n,a[100005],c[100005];
	while(~scanf("%d",&n)){
	memset(c,0,sizeof(c));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
				c[a[i]]++;
				c[a[i]+1]++;
				c[a[i]-1]++;			
				if(i==n-1){
				sort(c,c+100005,cmp);
				printf("%d\n",c[0]);
				}	
		}
	}
	return 0;
} 