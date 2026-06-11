#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const char sp = ' ';
const char cmm = ',';
const int MOD = 1000000007;

using ll = long long;

ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powMod(ll b, ll e, ll m){ll r=1;while(e>0){if(e&1)r=(r%m)*(b%m)%m;b=(b%m)*(b%m)%m;e>>=1;}return r;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<typename T>
void ppp(T n){cout << n << endl;}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
    cout << '[';
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len-1) s << ", ";
	}
    cout << ']';
	return s;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y;
	cin >> x >> y;

	if(x+y <= 1) ppp("Brown");
	else if(abs(x-y) <= 1) ppp("Brown");
	else ppp("Alice");

    return 0;
}
