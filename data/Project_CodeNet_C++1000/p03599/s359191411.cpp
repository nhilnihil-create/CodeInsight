#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
ll lst[Max];
int ls[Max];

int main()
{
	PRE
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double res = 0, r1=0, r2=0;
	for(int i=0;i<=f/(100*a);i++)
		for (int j = 0;j <= f - a * i * 100;j++)
		{
			int s = min(f - 100 * (i * a + b * j), (i*a+ b*j) * e);
			for (int k = 0;k <= s / c;k++)
			{
			
				int u = (s - k * c) / d;
				if (double(u * d + k * c) / (u * d + k * c + (i * a + j * b) * 100) > res)
				{
					res = (double(u * d + k * c) / (u * d + k * c + (i * a + j * b) * 100));
					r1 = u * d + k * c + (i * a + j * b) * 100;
					r2 = u * d + k * c;
				}
			}
		}
	if (res != 0)
		cout << r1 << " " << r2 << endl;
	else cout << a * 100 << " " << 0 << endl;
}