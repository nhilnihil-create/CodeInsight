#include<iostream>
#include<set>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int n, k;
	cin >>n >>k;

	int g = 0, mx = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >>a;
		g = gcd(g, a);
		mx = max(mx, a);
	}
	
	if(k % g == 0 && k <= mx){
		cout <<"POSSIBLE\n";
	}
	else{
		cout <<"IMPOSSIBLE\n";
	}

	return 0;
}
