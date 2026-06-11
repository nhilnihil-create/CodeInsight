#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& x: a){
		cin >> x;
	}
	int devide = 2; // 0+ 1-
	int count = 0;
	for(int i = 0; i < n-1;i++){
		int mi;
		mi = a.at(i+1) - a.at(i);
		if(devide == 2){
			if(mi < 0) devide = 1;
			if(mi > 0) devide = 0;
		}
		if((mi > 0) && (devide == 1)){
			count++;
			devide = 2;
		}
		if((mi < 0) && (devide == 0)){
			count++;
			devide = 2;
		}
	}

	cout << count+1 << endl;
}
