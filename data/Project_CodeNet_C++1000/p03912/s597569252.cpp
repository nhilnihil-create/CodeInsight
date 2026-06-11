#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<iterator>
#include<set>
#include<queue>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;



int main(){
	int n,m; cin >> n >> m;
	vector<int> howmany(100000+1);
	vector<int> modMany(m);
	rep(i,n){
		int temp; cin >> temp;
		howmany[temp] += 1;
		modMany[temp % m] += 1;
	}
	vector<int> modEqual(m);
	rep(i, 100000+1){
		if(i % m != 0)
			modEqual[i % m] += howmany[i] / 2;
	}
	int dame = 0;
	rep(i, m/2 + 1){
		if(i == 0)
			dame += modMany[0] % 2;
		else if(i == m/2 && m % 2 == 0){
			dame += modMany[m/2] % 2;
		}
		else{
			int counterpart = m - i;
			int i1 = modMany[i] - min(modMany[i], modMany[counterpart]);
			int i2 = modMany[counterpart] - min(modMany[i], modMany[counterpart]);
			if(i1 % 2 == 0)
				dame += max(0, i1 - 2*modEqual[i]);
			else
				dame += max(1, i1 - 2*modEqual[i]);
			if(i2 % 2 == 0)
				dame += max(0, i2 - 2*modEqual[counterpart]);
			else
				dame += max(1, i2 - 2*modEqual[counterpart]);

		}
	}
	int res = (n - dame) / 2;
	cout << res << endl;
}