#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
int MOD = 1000000007;
double PI = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define For(i,s,n) for (int i=s;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vs vector<string>
#define All(c) (c).begin(), (c).end()
#define Print(x) cout<<(x)<<"\n"



int main() {

	string S;
	cin >> S;

	rep(i, 12) {
		if (i == 4) cout << ' ';
		cout << S[i];
	}
	cout << endl;

}