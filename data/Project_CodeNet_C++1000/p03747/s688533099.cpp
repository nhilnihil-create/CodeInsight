#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;

llint n, l, t;
llint x[100005], w[100005];
vector<llint> vec[2];
llint ans[100005];

int main(void)
{
	cin >> n >> l >> t;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> w[i];
		w[i]--;
		vec[w[i]].push_back(x[i]);
	}
	t *= 2;
	
	for(int i = 0; i < n; i++){
		llint z = i;
		if(w[i] == 0){
			z += t/l * vec[1].size(), z %= n;
			if(x[i]+t%l < l) z += upper_bound(vec[1].begin(), vec[1].end(), x[i]+t%l) - lower_bound(vec[1].begin(), vec[1].end(), x[i]), z %= n;
			else{
				z += vec[1].end() - lower_bound(vec[1].begin(), vec[1].end(), x[i]), z %= n;
				z += upper_bound(vec[1].begin(), vec[1].end(), x[i]+t%l-l) - vec[1].begin(), z %= n;
			}
			ans[z] = (x[i]+t/2)%l;
		}
		else{
			z += n - t/l * vec[0].size() % n, z %= n;
			if(x[i]-t%l >= 0) z += n - (upper_bound(vec[0].begin(), vec[0].end(), x[i]) - lower_bound(vec[0].begin(), vec[0].end(), x[i]-t%l)) % n, z %= n;
			else{
				z += n - (upper_bound(vec[0].begin(), vec[0].end(), x[i]) - vec[0].begin()) % n, z %= n;
				z += n - (vec[0].end() - lower_bound(vec[0].begin(), vec[0].end(), x[i]-t%l+l)) % n, z %= n;
			}
			ans[z] = (x[i]-t/2%l+l)%l;
		}
	}
	
	for(int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
}