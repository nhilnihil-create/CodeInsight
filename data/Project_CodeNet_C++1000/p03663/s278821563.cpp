#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

string N;

bool ask(string x)
{
	cout << "? " << x << "\n"; fflush(stdout);
	char res;
	cin >> res; fflush(stdout);
	return (res == 'Y');
	//cout << "? " << x << " " << ((x > N && stoll(x) > stoll(N)) || (x <= N && stoll(x) <= stoll(N))) << "\n"; fflush(stdout);
	//return ((x > N && stoll(x) > stoll(N)) || (x <= N && stoll(x) <= stoll(N)));
}

void done(lli x)
{
	cout << "! " << x << "\n"; fflush(stdout);
	exit(0);
}

lli digs()
{
	lli v = 1ll;
	for(lli i = 1;i <= 15ll;i++)
	{
		v *= 10ll;
		if(!ask(to_string(v))) return i;
	}
	v = 1ll;
	for(lli i = 1;i <= 15ll;i++)
	{
		v *= 10ll;
		if(ask(to_string(v-1))) done(v/10ll);
	}
	return -1;
}

void solve(lli d)
{
	string q;
	for(lli i = 0;i < d;i++) q += "0";
	for(lli i = d;i > 0;i--)
	{
		lli L = 0ll, R = 9ll, ans = -1;
		while(L <= R)
		{
			lli mid = (L+R)/2ll;
			q[d-i] = char(mid+'0');
			if(ask(q+"0")) R = mid-1ll; 
			else L = mid+1ll, ans = max(ans, mid);
		}
		q[d-i] = char(ans+'0');
	}
	lli res = stoll(q)+1ll;
	done(res);
}

int main(void)
{
	//cin >> N;
	lli x = digs();
	solve(x);
}