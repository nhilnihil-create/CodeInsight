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
	if(a%3==0||b%3==0||(a+b)%3==0)
	cout<<"Possible";
	else
	cout<<"Impossible";
	return 0;
}
