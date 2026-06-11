#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define nl '\n'
#define pii pair <ll, ll>
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323846264
#define y1 abacaba
#define fn "abc"
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pcnt(i) __builtin_popcount(i)
#define lcm(a,b) (a * b) / __gcd(a, b)
#define chill_wave ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pressF freopen("rsq.in", "r", stdin); freopen("rsq.out", "w", stdout);

using namespace std;

const long long MXN = 1e6 + 23;
const long long MAXN = 2e3 + 1;
const long long MOD = 1e9 + 7;
const long long MAXLOG = 20;
const long long INF = 1e18;

inline void f_math(bool ok = 0) { chill_wave if(ok) { pressF; } }

//int dx[]= {1,0,-1,0}; int dy[]= {0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0}; int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

ll n, a[MXN], A, B, c[MXN];

void init() {
	for(int i = 1; i <= n; i++) c[i] = a[i];
}

int main() {

    f_math();
   	
 	cin >> n >> A >> B;    
 	for(int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}
 	sort(a + 1, a + 1 + n);
 	init();                                 
 	int l = 1, r = 1e9;
 	while(r - l > 1) {
 		int m = (l + r) / 2;
 		init();
 		for(int i = 1; i <= n; i++) {
 			c[i] -= (B * m);	 		
 		}
 		int col = m;
 		bool can = 1;
 		for(int i = n; i >= 1; i--) {
 			int cel = (c[i] + (A - B) - 1) / (A - B);
 			if(cel > col && c[i] > 0) {
 				can = 0;
 				break;					
 			}
 			col -= cel;			 		
 		}
 		if(can) {
 		 	r = m;
 		} else {
 		 	l = m;
 		}	
 	}
 	init();
 	for(int i = 1; i <= n; i++) {
 		c[i] -= (B * l);	 		
 	}
 	int col = l;
 	bool can = 1;
 	for(int i = n; i >= 1; i--) {
 		int cel = (c[i] + (A - B) - 1) / (A - B);
		if(cel > col && c[i] > 0) {
 			can = 0;
 			break;					
 		}
 		col -= cel;			 		
	}
	if(can) cout << l;
	else cout << r;
 	return 0;
}
