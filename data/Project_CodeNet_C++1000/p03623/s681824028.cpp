#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	int a,b,c;
	cin>>a>>b>>c;
	if(abs(a-b)>abs(a-c))
		cout<<"B";
	else
		cout<<"A";
	return 0;
}

