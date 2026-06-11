#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> v[100010];
map<int,int> mp;
int main(){
	int i,j,n,m,x;
	long long ans=0;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> x;
		v[x%m].push_back(x);
		mp[x]++;
	}
	
	ans += v[0].size()/2;
	for(i=1;i<=(m-1)/2;i++){
		int cnt = 0,a = v[i].size(),b = v[m-i].size();
		ans += min(a,b);
		if(a>b){
			sort(v[i].begin(),v[i].end());
			v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
			for(j=0;j<v[i].size();j++){
				cnt += mp[v[i][j]]/2;
			}
			
		}else{
			sort(v[m-i].begin(),v[m-i].end());
			v[m-i].erase(unique(v[m-i].begin(),v[m-i].end()),v[m-i].end());
				for(j=0;j<v[m-i].size();j++){
					cnt += mp[v[m-i][j]]/2;
				}
			}
		ans += min(max(a-b,b-a)/2,cnt);
	}
	if(m%2==0){
		ans += v[m/2].size()/2;
	}
	cout << ans << endl;
}
