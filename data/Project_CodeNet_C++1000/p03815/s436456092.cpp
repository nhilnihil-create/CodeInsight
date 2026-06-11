//

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long x; cin>>x;
	long long ans = x /11;
	if(ans*11 == x){
		cout<<ans*2<<endl;
	}
	else if(x-ans*11 > 6){
		ans++;
		cout<<ans*2<<endl;
	}
	else{
		ans = ans*2;
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}

