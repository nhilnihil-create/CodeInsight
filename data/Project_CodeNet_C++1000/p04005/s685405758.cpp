#include <bits/stdc++.h>
using namespace std;

#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n-1);i>=0;i--)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define D(a) cerr << #a << " = " << a << endl
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
typedef pair<int,int> pii;
typedef long long int ll;
typedef vector<int> vi;
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

	ll a,b,c;
	cin >> a >> b >> c;
	
	if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
		cout << 0 << endl;
	else {
		ll s1,s2,s3;
		s1 = a * b;
		s2 = a * c;
		s3 = b * c;
		s1 = min(s1,s2);
		cout << min(s1,s3) << endl;
	}
	
	
    return 0;
}
