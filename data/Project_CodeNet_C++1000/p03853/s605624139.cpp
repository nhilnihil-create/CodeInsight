#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mpi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{
	int h,w;
	cin >> h >> w;
	char m[h+1][w+1];
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin >> m[i][j];
		}
	}
	char p[2*h + 1][w+1];
	for(int i=1;i<=2*h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			p[i][j] = m[(i+1)/2][j];
		}
	}
	for(int i=1;i<=2*h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cout << p[i][j];
		}
		cout << "\n";
	}
	return 0;
}
