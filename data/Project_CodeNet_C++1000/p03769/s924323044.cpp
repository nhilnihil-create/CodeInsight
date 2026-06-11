#include <bits/stdc++.h>
#define x first
#define y second
#define y1 secondy1
#define rank tipa_rank
#define pb push_back
#define mp make_pair
#define pow10 tipa_pow10
#define ll long long
#define INF 1000000000
#define EPS 1e-9
#define EPS2 1e-8
#define PI acos(-1.0)
using namespace std;
const int MOD = INF + 7;
int a = 1;
deque<int> permut;
void f(ll X)
{
	if(X == 1)
		return;
	int v = a++;
	if(not(X % 2))
	{
		f(X / 2);
		permut.push_back(v);
	}
	else
	{
		permut.push_back(v);
		f(X - 1);
	}
}
int main()
{
	ll N;
	cin >> N;
	N++;
	f(N);
	int x = permut.size();
	for(int i = 0; i < x; i++)
	{
		permut[i] = x - permut[i] + 1;
	}
	for(int i = 0; i < x; i++)
		permut.push_back(i + 1);
	cout << permut.size() << endl;
	for(int i = 0 ; i < permut.size(); i++)
		cout << permut[i] << " ";
	cout << endl;
}
