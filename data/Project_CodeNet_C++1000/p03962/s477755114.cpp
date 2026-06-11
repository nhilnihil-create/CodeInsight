//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	set<ll> s;
	for(ll i=1;i<=3; i++)
	{
	    cin>>a;
	    s.insert(a);
	}
	cout<<s.size();
	return 0;
}
