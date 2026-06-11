#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;

int A,B,C;

int main(){
	cin>>A>>B>>C;
	if((A%2==0)||(B%2==0)||(C%2==0)) cout<<"0\n";
	else {
		ll Min=1e18+1;
		Min=min(1ll*A*B,1ll*B*C);
		Min=min(Min,1ll*A*C);
		cout<<Min;
	}
	return 0;
} 