#include<bits/stdc++.h>
using namespace std;
long long ans,a,b,n,i,weizhi[100005];
int main(){
    cin>>n>>a>>b;
    for(i=1;i<=n;i++){
    	cin>>weizhi[i];
	}
    for(i=2;i<=n;i++){
    	ans+=min((weizhi[i]-weizhi[i-1])*a,b);
	}
    cout<<ans<<endl;
}