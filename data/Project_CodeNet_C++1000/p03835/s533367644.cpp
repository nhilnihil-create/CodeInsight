#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	int s,k,cnt=0;
	cin>>k>>s;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
			if(s-i-j<=k&&s-i-j>=0)
				cnt++;
	cout<<cnt;
	return 0;
}

