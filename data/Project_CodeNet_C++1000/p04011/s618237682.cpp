//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,k,x,y;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>n>>k>>x>>y;
	if(n<=k)
	cout<<x*n;
	else
	cout<<((x*k)+(y*(n-k)));
	return 0;
}
