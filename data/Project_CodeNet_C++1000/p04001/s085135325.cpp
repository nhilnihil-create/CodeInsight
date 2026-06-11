#include <bits/stdc++.h>
using namespace std;
#define INF 100005

string a;
long long ans;
int n;
string str;

void rec(int pos)
{
	if(pos==n-1)
	{
		str.push_back(a[pos]);
		stringstream ss(str);
		long long num;
		while(ss >> num)
		{
			ans=ans+num;
		}
		str.pop_back();
		return;
	}
	str.push_back(a[pos]);
	rec(pos+1);
	str.pop_back();
	str.push_back(a[pos]);
	str.push_back(' ');
	rec(pos+1);
	str.pop_back();
	str.pop_back();
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> a;
    n=a.size();
    rec(0);
    cout << ans << endl;
}