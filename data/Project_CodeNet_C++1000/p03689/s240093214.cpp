#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF LLONG_MAX
#define eps LDBL_EPSILON
#define moder 1000000007
#define pie 3.141592653589793238462643383279
#define P std::pair<int,int>
#define prique priority_queue
using namespace std;
int a,b,c,d;
int ans[510];
signed main(){
	cin>>a>>b>>c>>d;
	if(a%c==0&&b%d==0){
		puts("No");
		return 0;
	}
	puts("Yes");
	bool flag=false;
	if(a%c==0){
		swap(a,b);
		swap(c,d);
		flag=true;
	}
	ans[a]=10000;
	for(int i=a-1;i>=0;i--){
		if(i+c<=a)ans[i]=ans[i+c]+1;
		else ans[i]=ans[i-1]-1;
	}
	if(flag){
		rep(i,b){
			for(int j=1;j<=a-1;j++)cout<<ans[j]-ans[j-1]<<" ";
			cout<<ans[a]-ans[a-1]<<endl;
		}
	}
	else{
		for(int i=1;i<=a;i++){
			rep(j,b-1)cout<<ans[i]-ans[i-1]<<" ";
			cout<<ans[i]-ans[i-1]<<endl;
		}
	}
	return 0;
}