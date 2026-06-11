//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll x,t;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>x>>t;
	cout<<max(0ll,x-t);
	return 0;
}
