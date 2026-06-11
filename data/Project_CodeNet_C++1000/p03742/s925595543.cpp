#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll x,y;
	cin>>x>>y;
	if(llabs(x-y)<2) printf("Brown\n");
	else printf("Alice\n");
	return 0; 
} 