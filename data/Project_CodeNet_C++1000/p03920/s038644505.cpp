#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N;

	cin >> N;
	cerr << endl;

	llong sum = 0;
	for(int i = 1; i <= N; i++){
		sum += i;
		if(sum >= N){
			int no = sum - N;
			for(int j = 1; j <= i; j++)
				if(j != no)
					cout << j << endl;
			break;
		}
	}

	return 0;
}