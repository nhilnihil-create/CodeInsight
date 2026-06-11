#include<bits/stdc++.h>
using namespace std;

int n,a[100100];
bool chk(){
	int cnt=0;
	for(int i=1;i<=n;++i)cnt+=a[i]&1;
	if((n-cnt)&1)return 1;
	if(cnt>=2||a[1]==1)return 0;
	int g=0;
	for(int i=1;i<=n;++i)g=__gcd(g,a[i]/2);
	for(int i=1;i<=n;++i)a[i]/=g*2;
	return !chk();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<(chk()?"First\n":"Second\n");
	return 0;
}
