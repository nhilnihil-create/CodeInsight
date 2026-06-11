#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false) , cin.tie(0) ,cout.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int ans = (a + b) * c;
	ans /=2;
	
	cout<<ans<<endl;
	return 0;
} 
