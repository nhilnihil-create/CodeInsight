#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 100003

int n, l, P[mx][20], q, a[mx], A, b;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> l;
	for(int i = 1; i <= n; i++){
		int in = upper_bound(a + 1, a + n + 1, a[i] + l) - a;
		in -= 1;
		P[i][0] = in;
		// debug(i);
		// debug(in);
	}
	for(int j = 1; j <= 18; j++)
		for(int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	cin >> q;
	while(q--){
		cin >> A >> b;
		if(A > b)
			swap(A, b);
		int jaw = 1;
		for(int i = 18; i >= 0; i--){
			if(P[A][i] < b){
				A = P[A][i];
				// debug(A);
				jaw += 1 << i;
			}
		}
		cout << jaw << '\n';
	}
}