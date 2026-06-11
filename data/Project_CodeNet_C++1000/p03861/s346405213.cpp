#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll a,b,x,cnt=0;
	cin  >> a >> b >> x;
	
	cnt = (b/x)-(a/x);

	if(a % x == 0){
		cnt++;
	}

	cout << cnt << endl;
	
	return 0;
}