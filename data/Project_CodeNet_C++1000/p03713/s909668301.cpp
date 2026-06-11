#include<bits/stdc++.h>
using namespace std;

#define INF (1LL<<60)

long long Solve(long long H, long long W){
	long long ans=INF;

	for(long long h=1;	h<H; h++){
		long long w=W/2,	Sa,Sb,Sc,M,m;
		Sa=h*W;

		// 1.
		Sb=(H-h)*w;
		Sc=(H-h)*(W-w);

		M=max(Sa, max(Sb,Sc));	m=min(Sa, min(Sb,Sc));
		ans=min(ans,M-m);

		//2,
		long long tmp=(H-h)/2;
		Sb=tmp*W;
		Sc=(H-h-tmp)*W;

		M=max(Sa, max(Sb,Sc));	m=min(Sa, min(Sb,Sc));
		ans=min(ans,M-m);
	}
	return ans;
}

int main(){
	long long H,W;	cin>>H>>W;
	
	cout<<min(Solve(H,W), Solve(W,H))<<endl;

	return 0;
}
