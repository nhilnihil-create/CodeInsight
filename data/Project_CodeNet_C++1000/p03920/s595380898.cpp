#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
ll N;

int main(){
	cin >> N;
	while(N > 0){
		int k = ceil((sqrt(1+8*N)-1)/2);
		cout << k << endl;
		N -= k;
	}

	return 0;
}
