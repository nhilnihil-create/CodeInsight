#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int N; cin>>N;
	vector<int> a(N+1,0);
	rep(i,N) cin>>a[i+1];

	int now=1, count=0;
	set<int> old;
	old.insert(now);
	bool flg = false;
	while(!old.count(a[now])){
		now = a[now];
		old.insert(now);
		count++;
		if(now==2){
			flg = true;
			break;
		}
	}

	if(flg){
		cout << count << endl;
	}else{
		cout << -1 << endl;
	}
}
