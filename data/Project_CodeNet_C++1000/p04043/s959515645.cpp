#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b)/gcd
#define rep(i,n)   for(int i=0;i<n;i++)
#define Rep(i,n)   for(int i=1;i<=n;i++)
#define REP(i,j,n) for(int i=j;i<=n;i++)
#define fast   ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)


int main()
{ 
	fast;
	int ar[3];
	rep(i,3){
		cin>>ar[i];
	}
	int cnt=0;
	rep(i,3){
		if(ar[i]==5) cnt++;
	}
	if(cnt==2){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;

}