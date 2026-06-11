#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n,c,k;
	cin >> n >> c >> k;
	vector<int> t(n);
	rep(i,n) cin >> t[i];
	sort(t.begin(),t.end());
	int l=-1; //バスの出発時刻
	int cnt=0;
	int res=0;
	rep(i,n){
		if(t[i]>l||cnt==c){
			l = t[i]+k;
			res++;
			cnt=1;
		}
		else
		{
			cnt++;
		}
		
	}
	cout << res << endl;
	return 0;
}

