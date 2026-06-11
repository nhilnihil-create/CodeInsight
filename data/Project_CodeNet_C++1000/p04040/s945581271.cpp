#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAX = 200001;
int mult(int a , int b)
{
	return (a * (LL)b) % mod;
}
int add(int a , int b)
{
	return a + b < mod ? a + b : a + b - mod;
}
int sub(int a , int b)
{
	return a - b >= 0 ? a - b : a - b + mod;
}
int modPow(int a , int step)
{
	int ans = 1;
	while(step)
	{
		if(step & 1)
			ans = mult(ans , a);
		step >>= 1;
		a = mult(a , a);
	}
	return ans;
}
vector<int> fact(MAX) , inv(MAX);
int c(int n , int k)
{
	return mult(fact[n] , mult(inv[n - k] , inv[k]));
}
int ways(int h , int w)
{	
	return c(h + w - 2, w - 1);
}
int main()
{	
	int H , W , A , B;
	cin >> H >> W >> A >> B;
	fact[0] = inv[0] = 1;
	for(int i = 1; i < fact.size(); i++)
	{
		fact[i] = mult(fact[i - 1] , i);
		inv[i] = modPow(fact[i] , mod - 2);
	}
	int ans = ways(H , W);
	for(int i = 0; i < B; i++)
	{
		ans = sub(ans , mult(ways(H - A , i + 1) , ways(A , W - i)));
	}
	cout << ans;
	return 0;
}
