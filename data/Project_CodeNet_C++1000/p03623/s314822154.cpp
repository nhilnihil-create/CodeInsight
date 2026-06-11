#include<bits/stdc++.h>
using namespace std;
int main()
{
    	cin.tie(0);
        ios::sync_with_stdio(0);
    	int x,a,b;
    	cin>>x>>a>>b;
    	if(abs(x-a)<abs(x-b))cout<<'A';
    	else 
    		cout<<'B';
 	return 0;
}
