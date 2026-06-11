#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int level,h,w,n,k=1;
	scanf("%d %d",&h,&w);
	scanf("%d",&n);
	int c[105][105];
	vector<int> a;
	a.resize(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=h;i++){
		if(i&1){
			for(int j=1;j<=w;j++){
				if(a[k]){
					c[i][j]=k;
				}
				else{
					k++;
					c[i][j]=k;	
				}
				a[k]--;
			}
		}
		else{
			for(int j=w;j>=1;j--){
				if(a[k]){
					c[i][j]=k;
				}
				else{
					k++;
					c[i][j]=k;	
				}
				a[k]--;
			}
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(j!=1) printf(" ");
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}