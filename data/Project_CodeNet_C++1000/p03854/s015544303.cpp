#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI = 3.141592653589793;

void solve()
{
	string s;
	cin >> s;
	string cur ;
	reverse(all(s));
	for(char c : s)
	{
		cur+=c;
		if(cur=="maerd" || cur == "remaerd" || cur=="esare" || cur == "resare") cur.clear();
	}
	if(cur.size()==0) cout << "YES";
	else cout << "NO";
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
