#include<iostream>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n;
	cin>>n;
	int k=(int)((-1+sqrt(1+8*n))/2);
	int res=n-k*(k+1)/2;
	int rm,push;
	bool check=(n==k*(k+1)/2)?true:false;
	loop(i,k+1,n+1){
		if((i-res)<=k){
			rm=i-res;
			push=i;
			break;
		}
	}
	loop(i,1,k+1){
		if(i==rm)continue;
		cout<<i<<endl;
	}
	if(!check)cout<<push<<endl;
	return 0;
}