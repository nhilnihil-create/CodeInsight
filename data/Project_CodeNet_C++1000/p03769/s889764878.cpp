#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N; cin >> N; int tms = 1; while((1ll << tms) - 1 <= N) ++tms;
	N -= (1ll << (tms - 1)) - 1; int cnt = 1; static int pos[103];
	for(int i = tms / 2 ; i ; --i){
		long long fac = 1; for(int j = 1 ; j <= i ; ++j) fac = fac * (tms - j + 1) / j;
		while(N >= fac){N -= fac; pos[++cnt] = i;}
	}

	vector < int > ans; int cnt1 = cnt;
	for(int i = 6 ; i >= 2 ; --i){
		while(N >= (1 << (i - 1)) - 1){N -= (1 << (i - 1)) - 1; ++cnt1; for(int j = 1 ; j <= i ; ++j) ans.push_back(cnt1);}
	}
	for(int i = 1 , p = cnt ; i <= tms ; ++i){ans.push_back(1); while(pos[p] == i) ans.push_back(p--);}
	for(int i = 2 ; i <= cnt ; ++i) ans.push_back(i);
	cout << ans.size() << endl;
	for(auto t : ans) cout << t << ' ';
	return 0;
}
	
