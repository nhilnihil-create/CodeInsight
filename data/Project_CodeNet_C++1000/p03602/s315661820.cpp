//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long int LL;
int a[303][303];
int b[303][303];
int c[303][303];
int n;
bool check(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j]) return false;
	return true;
}
int main(void){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			c[i][j]=b[i][j]=a[i][j];
		}
	for(int k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(i==k || k==j || i==j) continue;
				b[i][j]=min(b[i][j], b[i][k]+b[k][j]);
				c[i][j]=b[i][j];
			}
	if(!check()){
		printf("-1\n");
	}else{
		for(int k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					if(i==k || k==j || i==j) continue;
					if(c[i][j]==b[i][k]+b[k][j]) c[i][j]=0;
				}
		LL l=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				l+=c[i][j];
		printf("%lld\n",l/2);
	}
    return 0;
}
