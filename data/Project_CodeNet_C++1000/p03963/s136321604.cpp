#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll a, b, c;
    cin>>a>>b;
    c = pow(b-1, a-1);
    if(a == 1)
    {
    	cout<<b<<endl;
    	return 0;
    }
    else
    {
    	cout<<c*b<<endl;
    }
    return 0;
}