#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	cout<<3*(n-__gcd(n,m))<<endl;
	return 0;
}