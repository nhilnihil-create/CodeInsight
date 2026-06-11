#include <bits/stdc++.h>

using namespace std;

int main () {
	int N,x; cin >> N >> x;
    if(x==1||x==2*N-1) cout << "No" << endl;
	else {
		vector<int> ans(2*N-1);
		for(int i=0;i<2*N-1;++i) ans[i]=i+1;
		swap(ans[x-1],ans[N-1]);
		if(ans[N-1]<ans[N-2]&&ans[N-1]<ans[N]) swap(ans[0],ans[N-2]);
		else if(ans[N-1]>ans[N-2]&&ans[N-1]>ans[N]) swap(ans[N],ans[2*N-2]);
		cout << "Yes" << endl;
		for(int i=0;i<2*N-1;++i) cout << ans[i] << endl;
	}
	
    return 0;
}