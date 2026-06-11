#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n;
	cin>>n;
	int x=1;
	while(x<=n)x*=2;
	x/=2;
	cout<<x;
	
}