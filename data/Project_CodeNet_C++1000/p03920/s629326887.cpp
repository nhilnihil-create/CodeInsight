#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<bool> ans;
	for(int i=1;i<=n;++i){
		if(i*(i+1)/2>=n){
			ans.resize(i+1,true);
			ans[i*(i+1)/2-n]=false;
			break;
		}
	}
	for(int i=1;i<ans.size();++i){
		if(ans[i]) cout << i << endl;
	}
}