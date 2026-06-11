#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200200;
const int mod = 1e9 + 7;

inline bool ask(string cur)
{
	cout << "? ";
	cout << cur << endl;
	string s;
	cin >> s;
	return s == "Y";
}

inline void print(string s)
{
	cout << "! " << s << endl;
	exit(0);
}

inline void solve_step()
{
	string res = "";
	for(int i = 1; i <= 11; ++i)
	{
		string cur = res;
		if(i == 1) cur += '2';
		else cur += '1';
		if(ask(cur))
			print(res + (i == 1 ? "1" : "0"));
		res += (i == 1 ? "1" : "0");
	}
}

int n;
int main()
{
	string check = "";
	int len = -1;
	for(int i = 1; i <= 11; ++i)
	{
		string res = check;
		if(i == 1) res += '1';
		else res += '0';
		if(!ask(res+ ""))
		{
			len = i - 1;
			break;
		}
		check += (i == 1 ? "1" : "0");
	}	
	if(len == -1)                     
		solve_step();
	else
	{
		string ans = "";
		for(int p = 1; p <= len; ++p)
		{
			int l = -1, r = 9;
			if(p == 1) l++;
			while(l + 1 < r)
			{
				int m = l + r >> 1;
				string check = ans;
				check += char(m + '0');
				for(int j = p + 1; j <= len + 1; ++j)
					check += '9';
				if(!ask(check))
					l = m;
				else
					r = m;
			}	
			ans += char(r + '0');
		}
		print(ans);
	}
	return 0;
}