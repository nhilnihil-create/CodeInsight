
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b<a)
    {
		
		long long e = a-b;
		cout<<(c*b)+(d*e)<<endl;
	}
	else
	{
		cout<<c*a<<endl;
	}
    
    return 0;
}
