#include<bits/stdc++.h>
#define  fuckit(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
int main()
{
	fuckit();
	int h,w,i,j;
	cin>>h>>w;
	char c[h+1][w+1],C[h*2+1][w];
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			cin>>c[i][j];
		}
	}
	for(i=1;i<=2*h;i++){
		for(j=1;j<=w;j++){
			C[i][j]=c[(i+1)/2][j];
		}
	}
	for(i=1;i<=2*h;i++){
		for(j=1;j<=w;j++){
			cout<<C[i][j];
		}
		cout<<"\n";
	}
	return 0;	
}
