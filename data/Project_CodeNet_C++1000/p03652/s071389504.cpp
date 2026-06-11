#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N,M;
	cin>>N>>M;
	vector<vector<int>>a(N,vector<int>(M));
	REP(i,N)REP(j,M){
		cin>>a[i][j];
		a[i][j]--;
	}
	auto f = [&](int x)->bool{
		vector<int>ng(M,0);
		REP(_,M){
			vector<int>tmp(N,-1);
			vector<int>sum(M,0);
			REP(j,M){
				int flg = 0;
				REP(i,N){
					if(tmp[i]!=-1)continue;
					if(ng[a[i][j]])continue;
					sum[a[i][j]]++;
					tmp[i] = a[i][j];
					if(sum[a[i][j]]>x){
						ng[a[i][j]] = true;
						flg = true;
						break;
					}
				}
				if(flg)break;
			}
			int ok = 1;
			REP(i,N)if(tmp[i]==-1)ok = 0;
			REP(j,M)if(sum[j]>x)ok = 0;
			if(ok)return true;
		}
		return false;
	};
	int l = 0, r = N + 1;
	while(r - l > 1){
		int c = (l + r) / 2;
		if(f(c)) r = c;
		else l = c;
	}
	cout << r << endl;
}
