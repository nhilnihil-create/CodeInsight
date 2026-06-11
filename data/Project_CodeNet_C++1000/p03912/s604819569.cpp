#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int numbers[100001];
int mods_pair[100001];
int mods_rest[100001];

int main(){
	
	for(int i = 0; i < 100001; i++){
		numbers[i] = 0;
		mods_pair[i] = 0;
		mods_rest[i] = 0;
	}
	
	int n, m;
	
	cin >> n >> m;
	
	int x;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		numbers[x]++;
	}
	
	for(int i = 0; i <= 100000; i++){
		mods_pair[i % m] += numbers[i] / 2 * 2;
		mods_rest[i % m] += numbers[i] % 2;
	}
	/*
	for(int i = 0; i < m; i++){
		cout << mods_pair[i] << " " << mods_rest[i] << endl;
	}
	*/
	int ans = 0;
	
	int id1, id2;
	
	for(int i = 1; i < (double)m / 2; i++){
		if((mods_pair[i] > 0 || mods_rest[i] > 0) && (mods_pair[m - i] > 0 || mods_rest[m - i] > 0)){
			if(mods_pair[i] + mods_rest[i] >= mods_pair[m - i] + mods_rest[m - i]){
				id1 = i;
				id2 = m - i;
			}else{
				id1 = m - i;
				id2 = i;
			}
			ans += mods_pair[id2] + mods_rest[id2];
			mods_rest[id1] -= mods_pair[id2] + mods_rest[id2];
			if(mods_rest[id1] < 0){
				mods_pair[id1] += mods_rest[id1];
				mods_rest[id1] = 0;
			}
			mods_pair[id2] = 0;
			mods_rest[id2] = 0;
		}
	}
	/*
	for(int i = 0; i < m; i++){
		cout << mods_pair[i] << " " << mods_rest[i] << endl;
	}
	*/
	if(mods_rest[0] > 0){
		ans += mods_rest[0] / 2;
		mods_rest[0] = 0;
	}
	if(m % 2 == 0){
		if(mods_rest[m / 2] > 0){
			ans += mods_rest[m / 2] / 2;
			mods_rest[m / 2] = 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		ans += mods_pair[i] / 2;
		mods_pair[i] = 0;
	}
	
	cout << ans << endl;
	/*
	for(int i = 0; i < m; i++){
		cout << mods_pair[i] << " " << mods_rest[i] << endl;
	}
	*/
	return 0;
}

