#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin>>n;

	map<ll,ll> mp;

	rep(i,n){
		int tmp; cin>>tmp;

		mp[tmp]++;
	}

	vector<ll> ans(n+1,0);

	for(auto e : mp){
		if(e.second >=2){
			ans.push_back(e.first);
		}
		if(e.second >=4){
					ans.push_back(e.first);
		}
	}

	sort(ans.begin(),ans.end(),greater<int>());

	writeln((ll)ans[0]*ans[1]);



}
