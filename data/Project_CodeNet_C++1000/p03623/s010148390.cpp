#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x,a,b;
	cin>>x>>a>>b;
	cout<<(abs(x-a)<abs(x-b)?"A":"B")<<endl;
	return 0;
}