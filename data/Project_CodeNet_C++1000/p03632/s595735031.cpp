#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int ans;
	int ans_max=min(b-a,d-c);
	if(a<c)
	{
		if(c>=b)
		{
			ans=0;
		}
		else
		{
			ans=min(abs(b-c),ans_max);
		}
	}
	else
	{
		if(a>=d)
		{
			ans=0;
		}
		else
		{
			ans=min(abs(d-a),ans_max);
		}
	}
	
	cout << ans << endl;
	return 0;
}
