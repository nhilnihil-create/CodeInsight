#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,a[2000500],b[2000005],r,l;
void work(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if((y-x)&1){
		if(n>=(y-x+1)/2){//cout<<"z"<<endl;
		    rep(i,x,(y+x)/2) b[i]=b[x];
		    rep(i,(y+x)/2+1,y) b[i]=b[y];
		}
		else{
			rep(i,x,x+n-1) b[i]=b[x];
			rep(i,x+n,y-n) if((i-x-n)%2==0) b[i]=b[x]; else b[i]=b[y];
			rep(i,y-n+1,y) b[i]=b[y];
		}
	}
	else{//cout<<"h";
	    rep(i,x,y) b[i]=b[x];
		if(n<=(y-x)/2) rep(i,x+n,y-n) if((i-x-n)%2==0) b[i]=1-b[x];else b[i]=b[x];
	}
}
bool check(int x){
//	cout<<x<<endl;
	rep(i,1,2*n-1) if(a[i]>=x) b[i]=1;else b[i]=0;
//	rep(i,1,2*n-1) cout<<b[i];cout<<endl;
	b[2*n]=2;
	int st=-1;
	rep(i,1,2*n-1){
		if(st!=-1 && b[i]==b[i+1]) work(st,i),st=-1;
		if(st==-1 && b[i]!=b[i+1]) st=i;
	}
	if(st!=-1) work(st,2*n-1);
//	rep(i,1,2*n-1) cout<<b[i];cout<<endl;
	return b[n];
}
int main(){
	scanf("%d",&n);
	rep(i,1,2*n-1) scanf("%d",&a[i]),r=max(r,a[i]);
    l=1;
    while(l<r){
    	int mid=(l+r+1)>>1;
    	if(check(mid)) l=mid;
    	else r=mid-1;
	}
	printf("%d",l);
	return 0;
}