//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a,b;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>a>>b;
	if(a==1)
	a+=13;
	if(b==1)
	b+=13;
	if(a>b)
	cout<<"Alice";
	else if(b>a)
	cout<<"Bob";
	else
	cout<<"Draw";
	return 0;
}
