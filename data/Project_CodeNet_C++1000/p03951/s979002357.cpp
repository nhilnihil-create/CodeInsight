#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;
ll n,ans,k;
ll ds(int uke){
	int now=0;
	for (int s=uke; s<n; s++){
		if (a[s]!=b[now]) break;
		now++;
	}
	return now;
}
int main(){
    scanf("%lld",&n);
    cin>>a>>b;
    ans=n*2;
    for (int s=0; s<n; s++){
    	k=ds(s);
		ans=min(ans,n*2-k);
	}
	printf("%lld\n",ans);
    return 0;
}