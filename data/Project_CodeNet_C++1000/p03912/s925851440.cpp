#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
	int n,m; cin >> n >> m;
	vector<int> v[m];
	vector<int> x(n);
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	sort(x.begin(),x.end());
	for(int i=0;i<n;i++){
		v[x[i]%m].push_back(x[i]);
	}
	ll ans=0;
	ans+=v[0].size()/2;
	if(m%2==0){
		ans+=v[m/2].size()/2;
	}
	for(int i=1;i<=(m-1)/2;i++){
		if(v[i].size()>v[m-i].size()){
			swap(v[i],v[m-i]);
		}
		int cnt=0;
		for(int j=0;j<v[m-i].size();j++){
			int cp=v[m-i][j];
			int res=0;
			while(cp==v[m-i][j]){
				res++;
				j++;
			}
			j--;
			cnt+=res/2;
		}
		ans+=min(cnt,(int)(v[m-i].size()-v[i].size())/2);
		ans+=v[i].size();
	}
	cout << ans << endl;
}
