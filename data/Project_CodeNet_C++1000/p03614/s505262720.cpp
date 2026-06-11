#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000000;
//INFにっているのは右端か左端

int n, a[100005];
vector< pair<int,int> > distv;

int main() {
	cin>>n;
	for(int i = 0; i< n; i++){
		cin>>a[i];
		a[i]--;
	}
	int ld=INF;
	bool flag = false;
	for(int i = 0; i< n; i++){
		if(flag)ld++;
		if(a[i] == i){
			if(distv.size() > 0) distv[distv.size()-1].second = ld;
			distv.push_back(make_pair(ld,-1));
			ld = 0;
			flag = true;
		}
	}
	if(distv.size() > 0) distv[distv.size()-1].second = INF;
	
	int ans = 0;
	
	for(int i = 0; i < distv.size(); i++){
		ans++;
		if(distv[i].second == 1){
			i++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}