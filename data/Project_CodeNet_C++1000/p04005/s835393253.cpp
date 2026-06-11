#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long a,b,c;
	cin>>a>>b>>c;
    if(a%2 && b%2 && c%2)//全为奇数 
    {
    	long long min=1;
        if(a<b)
        {
        	min*=a;
        	if(c<b) min*=c;
        	else min*=b;
		}
		else
		{
			min*=b;
			if(c<a) min*=c;
			else min*=a;
		}
		cout<<min<<endl;
	}
	else cout<<0<<endl;
	return 0;
} 