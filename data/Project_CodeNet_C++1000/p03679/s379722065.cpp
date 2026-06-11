#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll x,a,b;
    cin>>x>>a>>b;
    if(b<=a)
		cout<<"delicious";
	else if(x+a>=b)
		cout<<"safe";
	else
		cout<<"dangerous";  
    
    return 0;
}