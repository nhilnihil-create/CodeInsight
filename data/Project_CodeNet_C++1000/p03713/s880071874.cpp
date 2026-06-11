#include <bits/stdc++.h>
#define int long long
using namespace std;

int ma(int a,int b,int c){
	return max(a,max(b,c));
}

int mi(int a,int b,int c){
	return min(a,min(b,c));
}

int solve(int H,int W){
	int ans=10000000000;
	if(W>2){
		//cout<<"?"<<endl;
		if(W%3==0)ans=min(0LL,ans);
		else ans=min(ans,H);
	}
	if(H%2==0){
		if(W%3==0)ans=min(ans,0LL);
		else ans=min(ans,H/2);
	}
	if(H%2==1){
		for(int t=1;t<=W;t++){
			int S1=H*t;
			int S2=(W-t)*(H+1)/2;
			int S3=(W-t)*(H-1)/2;
			ans=min(ans,ma(S1,S2,S3)-mi(S1,S2,S3));
		}
	}
	return ans;
}

signed main(){
	int H,W; cin>>H>>W;
	int a=solve(H,W);
	int b=solve(W,H);
	// cout<<a<<endl;
	// cout<<b<<endl;
	cout<<min(a,b)<<endl;

}