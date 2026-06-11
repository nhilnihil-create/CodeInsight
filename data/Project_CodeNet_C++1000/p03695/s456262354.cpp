#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	vector<bool> col(10);
	int free=0;
	rep(i,N){
		if(a[i]<3200) col[a[i]/400]=true;
		else free++;
	}
	int ans1=0, ans2=0;
	rep(i,10) if(col[i]) ans1++;
	ans2=ans1+free;
	if(ans1==0 && free!=0) ans1=1;
	cout << ans1 << " " << ans2 << endl;

	return 0;
}