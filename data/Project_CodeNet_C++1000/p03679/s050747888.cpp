//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll x,a,b;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>x>>a>>b;
	if(b-a<=0)
	cout<<"delicious";
	else if(b-a<=x)
	cout<<"safe";
	else
	cout<<"dangerous";
	return 0;
}
