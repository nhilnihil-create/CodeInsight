//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int n, x;
	cin >> n >> x;
	set<int> s;
	int bot = 2*n-1;
	int ans[bot] = {};
	REP1(i, bot) s.insert(i);
	if(x == bot || x == 1) cout << "No" << endl;
	else if(n != 2){
		if(x == bot-1){
			ans[bot/2] = x;
			ans[bot/2 + 1] = x + 1;
			ans[bot/2 - 1] = x - 1;
			ans[bot/2 + 2] = x - 2;
			s.erase(x);
			s.erase(x+1);
			s.erase(x-1);
			s.erase(x-2);
		}
		else{
			ans[bot/2] = x;
			ans[bot/2 + 1] = x - 1;
			ans[bot/2 - 1] = x + 1;
			ans[bot/2 + 2] = x + 2;
			s.erase(x);
			s.erase(x-1);
			s.erase(x+1);
			s.erase(x+2);
		}
		REP(i, bot){
			if(ans[i]==0){
				//cout << s.size();
				ans[i] = *s.begin();
				s.erase(*s.begin());
			}
		}
		cout << "Yes" << endl;
		REP(i,bot) cout << ans[i] << endl;
	}
	else{
		cout << "Yes" << endl;
		REP1(i,bot) cout << i << endl;
	}
}