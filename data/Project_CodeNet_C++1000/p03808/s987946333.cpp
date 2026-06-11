//Littleboy123 Template 1.1

#include <bits/stdc++.h>
using namespace std;

//pragmas
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
*/

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define FOR(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define FORN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define FORNE(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define COUT(a) cout << (a) << '\n'
#define MEM(a,b) memset((a), (b), sizeof((a)))
#define MAX(a,b) (a) = max((a), (b))
#define MIN(a,b) (a) = min((a), (b))
#define nl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

//End of template

ll arr[100005];

int main(){
	init();

	//debug
	/*
	ifstream in("input.in");
	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out("out.txt");
	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	*/
	//end debug

	ll n;
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i];
	}
	ll gcd = arr[0];
	ll maks, pos;
	maks = INT_MIN;
	
	FOR(i, 1, n){
		gcd = __gcd(gcd, arr[i]);
	}
	//cout << gcd << endl;
	FOR(i, 0, n){
		arr[i] /= gcd;
	}
	
	int ones = 0;
	FOR(i, 0, n){
		if(arr[i] == 1)
			ones++;
		if(maks < arr[i]){
			maks = arr[i];
			pos = i;
		}
	}
	
	ll another = (n*n+n)/2;
	if(gcd % another == 0 && ones == n){
		cout << "YES" << nl;
		return 0;
	}
	if(n % gcd == 0 && gcd != 1){
		cout << "YES" << nl;
		return 0;
	}
	int flag = 0;
	int zero = 0;
	ll newpos;
	while(true){
		maks = INT_MIN;
		if(arr[pos] >= n){
			arr[pos]-= n;
			maks = arr[pos];
			newpos = pos;
		}
		else{
			flag = 1;
			break;
		}
		if(arr[pos] == 0)
			zero++;
		FORNE(i, pos-1, 0){
			if(arr[i] >= n+(i)-pos){
				arr[i] -= (n+(i)-pos);
				if(maks < arr[i]){
					maks = arr[i];
					newpos = i;
				}
			}
			else{
				flag = 1;
				break;
			}
			if(arr[i] == 0){
				zero++;
			}
		}
		FOR(i, pos+1, n){
			if(arr[i] >= i-pos){
				arr[i] -= i-pos;
				if(maks < arr[i]){
					maks = arr[i];
					newpos = i;
				}
			}
			else{
				flag = 1;
				break;
			}
			if(arr[i] == 0)
				zero++;
		}
		if(flag){
			break;
		}
		if(zero == n)
			break;
		pos = newpos;
	}
	if(flag)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}