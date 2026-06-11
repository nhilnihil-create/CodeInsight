#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < n;i++)
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}


signed main(){
	int N;
	cin >> N;
	vector<int>a(N),ans,id(N),def(N*N,-1);
	queue<int>q,ok;
	REP(i,N){
		cin >> a[i];a[i]--;
		def[a[i]] = i;
	}
	iota(id.begin(),id.end(),0);
	sort(id.begin(),id.end(),[&](int l,int r){return a[l]<a[r];});
	REP(i,N){
		REP(j,N-1-id[i])ok.push(id[i]);
		REP(j,N-1-(N-1-id[i]))q.push(id[i]);
	}
	REP(i,N*N){
		if(def[i] != -1)ans.push_back(def[i]);
		else{
			if(q.size()){
				ans.push_back(q.front());
				q.pop();
			}else{
				ans.push_back(ok.front());
				ok.pop();
			}
		}
	}
	vector<int>cnt(N,0);
	REP(i,N*N){
		cnt[ans[i]]++;
		if(def[i] != -1){
			if(cnt[def[i]] - 1 != def[i]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	REP(i,ans.size())cout << ans[i] + 1 << " \n"[i+1 == ans.size()];
}
