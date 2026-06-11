#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 8;
long long x[N], m[N] , w[N] , tmp , p , q , cnt , n , l , t;

int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> l >> t;
	for(int i = 0 ; i < n ; i++)
		cin >> x[i] >> w[i];
	for(int i = 1 ; i < n ; i++)
	{
		if(w[i] != w[0])
		{
			if(w[0] == 1)
			{
				q = (2 * t - (x[i] - x[0]) + l - 1) / l;
				cnt += q;
			}
			else
			{
				q = (2 * t + (x[i] - x[0]) - 1) / l;
				cnt -= q;
			}
			cnt += n;
			cnt %= n;
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(w[i] == 1)
		{
			m[i] = ((x[i] + t) % l + l) % l;
		}
		else
		{
			m[i] = ((x[i] - t) % l + l) % l;
		}
	}
	tmp = m[0];
	sort(m , m + n);
	if(w[0] == 1)
	{
		p = 0;
		for(p = 0 ; m[p] != tmp ; p++);
	}
	else
	{
		p = n - 1;
		for(p = n - 1 ; m[p] != tmp ; p--);
	}
	for(int i = 0 ; i < n ; i++)
		cout << m[(i + p - cnt + n) % n] << endl;
}