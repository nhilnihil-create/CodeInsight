#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define accum(x) accumulate((x).begin(),(x).end(),0)

int main(){
	int n; cin>>n;
	vector<int> v(9,0);
	rep(i,n){
		int a; cin>>a;
		if(a<400) v[0]=1;
		else if(a>=400&&a<800) v[1]=1;
		else if(a>=800&&a<1200) v[2]=1;
		else if(a>=1200&&a<1600) v[3]=1;
		else if(a>=1600&&a<2000) v[4]=1;
		else if(a>=2000&&a<2400) v[5]=1;
		else if(a>=2400&&a<2800) v[6]=1;
		else if(a>=2800&&a<3200) v[7]=1;
		else v[8]++;
	}
	int mx=accum(v);
	int mn=0;
	rep(i,8) mn+=v[i];
	if(v[8]==n) cout<<1<<" "<<mx<<endl;
	else cout<<mn<<" "<<mx<<endl;
}