#include<iostream>
#define N 100000
using namespace std;
int PSTs[N+1];
int PSTt[N+1];
string s, t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> t;
	int n = s.length();
	s = "$"+s;
	t = "$"+t;

	PSTs[0] = PSTt[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		PSTs[i] = PSTs[i-1]+(s[i]=='A' ? 1 : -1);
		PSTt[i] = PSTt[i-1]+(t[i]=='A' ? 1 : -1);
	}

	int Q; cin >> Q;
	while(Q--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout<<(((PSTs[b]-PSTs[a-1])-(PSTt[d]-PSTt[c-1]))%3==0 ? "YES" : "NO")<<'\n';
	}
	cout<<flush;
	return 0;
}