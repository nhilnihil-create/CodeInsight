#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int H,W,h,w,a[1111][1111],sum;
int main(){
	cin>>H>>W>>h>>w;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			a[i][j]=1000;
		}
	}
	for(int i=h;i<=H;i+=h){
		for(int j=w;j<=W;j+=w){
			a[i][j]=-((h*w-1)*1000+1);
		}
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			sum+=a[i][j];
		}
	}
	if(sum<=0){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(j!=1)cout<<" ";
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}
