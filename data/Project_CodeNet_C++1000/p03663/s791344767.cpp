#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll now = 1e9;
inline bool check(ll x)
{
    cout << "? " << x << endl;
    char res;
    cin >> res;
    return res == 'Y';
}
int main()
{
    if(check(now)) while(now > 1 && check(now - 1)) now /= 10;
    else
    {
        while(!check(now /= 10));
        ll l = now, r = now * 10;
        while(r - l > 1)
        {
            ll mid = (l + r) / 2;
            if(check(mid * 10)) r = mid;
            else l = mid;
        }
        now = r;
    }
    cout<<"! "<<now<<endl;
    return 0;
}
