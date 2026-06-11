#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;
int main(){
	cin >> N;
	vector<int> ans;
	while(N>0){
		ll l = 0,r = N;
		while(l+1<r){
			ll m = (l+r)/2;
			if(N-m<=m*(m-1)/2) r = m;
			else l = m;
		}
		ans.push_back(r);
		N -= r;
	}
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
}
