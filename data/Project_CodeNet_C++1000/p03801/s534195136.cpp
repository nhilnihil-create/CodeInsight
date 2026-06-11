#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,A[100010],ans[100010] = {0};
vector<P> v;
int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		v.push_back({A[i],i});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	v.push_back({0,1e9});
	ll mi = 1e9;
	for(int i=0;i<N;i++){
		mi = min(mi,v[i].second);
		ans[mi] += (i+1)*(v[i].first-v[i+1].first);
	}
	for(int i=1;i<=N;i++){
		cout << ans[i] << endl;
	}
}