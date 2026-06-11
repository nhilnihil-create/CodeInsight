#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	rep(i,N) a[i]--;
	int ans=0;
	rep(i,N) if(a[a[i]]==i) ans++;
	cout << ans/2 << endl;

	return 0;
}