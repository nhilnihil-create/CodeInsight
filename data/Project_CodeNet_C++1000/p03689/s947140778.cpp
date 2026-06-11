#include <bits/stdc++.h>
using namespace std;
const int N=550;
int n,m,h,w,a[N][N];
int main(){
    cin>>n>>m>>h>>w;
    if (n%h==0&&m%w==0) puts("No");
    else{
	puts("Yes");
	for (int i=1; i<=n; ++i){
	    for (int j=1; j<=m; ++j){
		if (i%h==0&&j%w==0)
		    a[i][j]=-(h*w-1)*2000-1;
		else
		    a[i][j]=2000;
		printf("%d ",a[i][j]);
	    }
	    printf("\n");
	}
    }
    return 0;
}
