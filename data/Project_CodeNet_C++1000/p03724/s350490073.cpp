//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n, k;
	cin >> n >> k;
	int ch[n+1] = {};
	REP(i, k){
		int a, b;
		cin >> a >> b;
		ch[a]++; 
		ch[b]++;
	}
	bool an = true;
	REP1(i,n) if(ch[i]%2 == 1) an = false;
	if (an) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	//cout << ans << endl;
}