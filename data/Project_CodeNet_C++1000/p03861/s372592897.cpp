#include <bits/stdc++.h>
using namespace std;



int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 

	long long a,b,x;
	cin>>a>>b>>x;
	long long cnt = abs(b/x - a/x);
	if(a%x==0)
		cnt++;
	cout<<cnt<<'\n';
    return 0;
		
}