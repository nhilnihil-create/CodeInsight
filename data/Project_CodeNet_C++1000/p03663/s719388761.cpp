# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <cstring>
# include <cmath>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <map>
# include <set>
# include <deque>
# include <iterator>
# include <functional>
# include <bitset>
# include <climits>
# include <ctime>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define odd(x) (x&1)
#define debug(x) cout << #x << " => " << x << endl
typedef long long ll;
typedef long double ld;
const ll oo = /*2 * 1000 * 1000 * 1000*/0x3f3f3f3f;
const int _cnt = 1000 * 1000;
const int _p = 1000 * 1000 * 1000 + 7;
//const int _p = 1007;
ll o(ll x) { return x%_p; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
//ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a / gcd(a, b)*b; }
using namespace std;

void file_put() {
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
}

int ten[15],nine[15];
ll l,r,mid,ans;
char t;

int main() {
    //file_put();
    
    ten[0]=1;
    for (int i=1; i<=9; i++) {
    	ten[i]=10*ten[i-1];
    	nine[i]=ten[i]-1;
	}
	printf("? %d\n",nine[9]);
	fflush(stdout);
	scanf("%c",&t);
	cin.ignore();
	if (t=='N') {
		printf("! %d\n",ten[9]);
		fflush(stdout);
		return 0;
	}
	printf("? %d\n",ten[9]);
	fflush(stdout);
	scanf("%c",&t);
	cin.ignore();
	if (t=='Y') {
		for (int i=1; i<=9; i++) {
			printf("? %d\n",nine[i]);
			fflush(stdout);
			scanf("%c",&t);
			cin.ignore();
			if (t=='Y') {
				printf("! %d\n",ten[i-1]);
				fflush(stdout);
				return 0;
			}
		}
	}
	for (int i=1; i<=9; i++) {
		printf("? %d\n",ten[i]);
		fflush(stdout);
		scanf("%c",&t);
		cin.ignore();
		if (t=='N') {
			l=ten[i-1]+1;
			r=ten[i]-1;
			break;
		}
	}
	while (l<=r){
		mid=(l+r)>>1;
		printf("? %lld\n",mid*10);
		fflush(stdout);
		scanf("%c",&t);
		cin.ignore();
		if (t=='Y') r=mid; else l=mid;
		if (l==r || l==r-1) break;
	}
	if (l+1==r) {
		printf("? %lld\n",l*10);
		fflush(stdout);
		scanf("%c",&t);
		cin.ignore();
		if (t=='N') l++;
	}
	printf("! %I64d\n",l);
	fflush(stdout);

    return 0;
}
