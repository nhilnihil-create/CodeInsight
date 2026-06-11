#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{	
	string s;
	cin >> s;

	int K;
	cin >> K;

	//先頭から1文字ずつaに近づける。
	int idx = 0;
	while (idx < s.size() && K > 0)
	{
		if (s[idx] != 'a')
		{
			int d = 'z' - s[idx] + 1;

			//zから1周してaにできる文字のみ行う。
			if (K >= d)
			{
				s[idx] = 'a';
				K -= d;
			}
		}
		
		idx++;
	}

	//Kが余っている場合は最後の文字に押し付け
	K %= 26;

	while (K > 0)
	{
		int d = 'z' - s[s.size() - 1] + 1;

		//zから1周してaにできる文字のみ行う。
		if (K >= d)
		{
			s[s.size() - 1] = 'a';
			K -= d;
		}
		else
		{
			s[s.size() - 1] += K;
			K = 0;
		}

		idx++;
	}


	cout << s << endl;

	return 0;
}