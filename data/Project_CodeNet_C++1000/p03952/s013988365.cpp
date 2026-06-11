#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define bas(x) #x << ": " << x << " "
#define prarr(x, n) cout << #x << ": "; for (int qsd = 0; qsd < n; qsd++) cout << x[qsd] << " "; cout << endl;
#define prarrv(x) cout << #x << ": "; for (int qsd = 0; qsd < (int)x.size(); qsd++) cout << x[qsd] << " "; cout << endl;
#define ppair(x) "(" << x.first << ", " << x.second << ")"
#define inside sl<=l&&r<=sr
#define outside sr<l||r<sl

typedef long long ll;

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int n, x;
	cin >> n >> x;
	if (x == 1 || x == 2*n-1) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		vector<int> ans(2*n);
		ans[n] = x;
		int cur = x;
		for (int i = n-1; i > 0; i--){
			cur -= 1;
			if (cur < 1) cur += 2*n-1;
			ans[i] = cur;
		}
		cur = x;
		for (int i = n+1; i < 2*n; i++){
			cur++;
			if (cur >= 2*n) cur -= 2*n-1;
			ans[i] = cur;
		}

		for (int i = 1; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
}