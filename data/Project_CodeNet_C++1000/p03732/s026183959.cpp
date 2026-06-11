#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ll N, W;
	cin >> N >> W;
	
	vector<vector<ll>> item(4,vector<ll>());
	
	ll w, v;
	cin >> w >> v;
	ll mini = w;
	
	item[0].push_back(v);
	
	rep(i, N-1){
		cin >> w >> v;
		item[w-mini].push_back(v);
	}
	
	SORT(item[0]);
	reverse(item[0].begin(), item[0].end());
	SORT(item[1]);
	reverse(item[1].begin(), item[1].end());
	SORT(item[2]);
	reverse(item[2].begin(), item[2].end());
	SORT(item[3]);
	reverse(item[3].begin(), item[3].end());
	
	vector<ll> sum0(item[0].size()+1, 0);
	rep(i, item[0].size()) sum0[i+1] = sum0[i] + item[0][i];
	vector<ll> sum1(item[1].size()+1, 0);
	rep(i, item[1].size()) sum1[i+1] = sum1[i] + item[1][i];
	vector<ll> sum2(item[2].size()+1, 0);
	rep(i, item[2].size()) sum2[i+1] = sum2[i] + item[2][i];
	vector<ll> sum3(item[3].size()+1, 0);
	rep(i, item[3].size()) sum3[i+1] = sum3[i] + item[3][i];
	
	ll ans = 0;
	rep(i, item[0].size()+1){
		rep(j, item[1].size()+1){
			rep(k, item[2].size()+1){
				rep(l, item[3].size()+1){
					if(mini*i + (mini+1)*j + (mini+2)*k + (mini+3)*l > W) break;
					ans = max(ans, sum0[i] + sum1[j] + sum2[k] + sum3[l]);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}