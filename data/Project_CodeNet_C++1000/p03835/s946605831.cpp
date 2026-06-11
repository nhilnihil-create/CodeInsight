#include<bits/stdc++.h>
using namespace std;
int k,s,i,j,l;
int main(){
	scanf("%d%d",&k,&s);
	for (i=0;i<=k;i++){
		for (j=0;j<=k;j++){
			if (s-i-j<=k&&s-i-j>=0) l++;
		}
	}
	printf("%d\n",l);
}