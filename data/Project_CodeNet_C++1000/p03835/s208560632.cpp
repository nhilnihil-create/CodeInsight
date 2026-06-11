#include<bits/stdc++.h>
#define YY "YES\n"
#define NN "NO\n"
#define f first
#define s second
#define LL long long
using namespace std;

LL n,tar,ans;
int main(){
	cin>>n>>tar;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (tar-(i+j)<=n && tar-(i+j)>=0) ans++;
		}
	}
	cout<<ans<<"\n";
}