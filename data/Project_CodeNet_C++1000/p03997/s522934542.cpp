#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b,h,ans;
	cin>>a>>b>>h;
	ans=(h/2)*(a+b);
	cout<<ans<<endl;
	return 0;
}