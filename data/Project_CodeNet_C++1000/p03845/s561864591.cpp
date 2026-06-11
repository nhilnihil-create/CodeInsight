#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main(){

	int sum=0;
	int n;
	cin >> n;
	int t[100]={0};
	REP(i,n){
		cin >> t[i];
	}
	int m;
	cin >> m;
	int p,x;
	REP(i,m){
		sum = 0;
		cin >> p >> x;
		REP(j,n){
			if(p==j+1)sum += x;
			else sum += t[j];
		}
		cout << sum << endl;
	}

    return 0;
}