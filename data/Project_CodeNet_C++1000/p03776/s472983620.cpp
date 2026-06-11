#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

//割られる数：a
//余りを求めるやつ：valid
long long Modinv(long long a, long long valid = INV)
{
	long long b = valid, u = 1, v = 0;
	while (a)
	{
		if (a < b)
		{
			swap(a, b);
			swap(u, v);
		}
		long long t = a / b;
		a -= t * b;
		u -= t * v;
	}
	v %= valid;
	if (v < 0)
		v += valid;
	return v;
}

void execute()
{
	int N, Cmin, Cmax;
	int r, n;
	lint sum = 0;
	double ave = 0;
	lint C = 1;
	lint ans = 0;

	cin >> N >> Cmin >> Cmax;

	vector<lint> data(N);
	for (int i = 0; i < N; i++)
	{
		lint tmp;
		cin >> tmp;
		data[i] = tmp;
	}

	sort(all(data), greater<lint>());

	lint last = data[0];
	r = 0;
	n = 0;
	for (int i = 0; i < Cmin; i++)
	{
		if (last == data[i])
			r++;
		else
			r = 1;
		last = data[i];
		sum += data[i];
	}

	ave = (double)(sum) / Cmin;

	cout << ave << endl;
	for (int i = 0; i < N; i++)
	{
		if (last == data[i])
			n++;
	}
	for (int i = 0; i < n; i++)
	{
		C *= (n - i);
		//C % INV;
		C /= (i + 1);
		//C *= Modinv(i + 1);
		//C % INV;

		if (r == Cmin)
		{
			if (r <= i + 1 && i + 1 <= r + Cmax - Cmin)
			{
				ans += C;
			}
		}
		else
		{
			if (i + 1 == r)
			{
				cout << C << endl;
				return;
			}
		}
	}

	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}