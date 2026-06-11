#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int cnt = 0;
	int n; cin >> n;
	vector<bool> bv;
	for(int i = 0; i < n; i++){
		int p; cin >> p;
		if(p == i+1){
			bv.push_back(1);
		}else{
			bv.push_back(0);
		}
	}

	if(bv[n-1]){
		cnt++;
		bv[n-2] = 0;
		bv[n-1] = 0;
	}


	for(int i = 1; i < n; i++){
		if(bv[i-1]){
			cnt++;
			bv[i-1] = 0;
			bv[i]= 0;
		}
	}
	
	cout << cnt << endl;
}