#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

lli upper, lower, mid, ans;


void binsearch(lli l, lli u)
{
	char deci;
	if( l == u)
	{
		ans = l;
		return;
	}
	lli mid = (l + u)/2;

	cout << "? "<< (mid*10) << "\n";
	fflush(stdout);

	cin >> deci;
	if( deci == 'Y')
	{
		binsearch(l, mid);
	}
	else
	{
		binsearch(mid+1, u);
	}
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	char deci;
	lli x = 1, checker = 10000000000;
	cout << "? "<< checker <<"\n";
	fflush(stdout);

	cin >> deci;

	if( deci == 'Y')
	{
		while(checker)
		{
			cout << "? "<< (checker*2)<< "\n";
			fflush(stdout);
			cin >> deci;
			if(deci == 'N')
				break;
			checker /= 10;
		}
		if( checker)
			cout << "! "<< (checker*10)<< "\n";
		else
			cout << "! 1\n";
		fflush(stdout);
		return 0;
	}
	else
	{
		while(true)
		{
			cout << "? "<< x<< "\n";;
			fflush(stdout);
			cin >> deci;

			if( deci == 'N')
				break;
			x *= 10;
		}
		upper = x-1;
		lower = x/10+1;

		binsearch(lower, upper);
		cout << "! "<< ans << "\n";
		fflush(stdout);
		return 0;
	}
}