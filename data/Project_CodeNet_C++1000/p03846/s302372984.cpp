#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind
#define rt (a); return (a); 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
llint gcd(llint a, llint b) {
	if (b > a)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
llint Tow(int n) {//2のn乗
	if (n == 0)return 1;
	llint x = Tow(n / 2);
	x %= mod;
	x *= x;
	x %= mod;
	if (n % 2 == 1)x *= 2;
	x %= mod;
	return x;
}
int main() {
	int n;
	cin >> n;
	hei(int) a(n);
	int zero = 0;
	hei(int) A;
	if (n%2 == 1) {
		rep(i, 0, n) {
			cin >> a[i];
			if (a[i] == 0)zero++;
			else A.push_back(a[i]);
		}
		if (zero!=1) {
		S:
			cout << 0 << endl;
			return 0;
		}
		sort(A);
		A.push_back(0);
		int x = 1;
		rep(i, 0, A.size()-1) {
			if (A[i] == A[i + 1])x++;
			else {
				if (x != 2)goto S;
				x = 1;
			}
		}
		llint ans = Tow(n / 2);
		cout << ans << endl;
	}
	else {
		rep(i, 0, n) {
			cin >> a[i];
			if (a[i] == 0) {
				cout << 0 << endl;
				return 0;
			}
			A.push_back(a[i]);
		}
		sort(A);
		A.push_back(0);
		int x = 1;
		rep(i, 0, A.size() - 1) {
			if (A[i] == A[i + 1])x++;
			else {
				if (x != 2)goto S;
				x = 1;
			}
		}
		llint ans = Tow(n / 2);
		cout << ans << endl;
	}
	return 0;
}