#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	while(n--){
		int s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	int suma = accumulate(v.begin(),v.end(),0);
	if(suma%10 == 0){
		for(auto x:v){
			if((suma-x)%10 != 0){
				cout << suma-x;
				return 0;
				}
			}

		cout << 0;
				}
	else{cout<< suma;}
}
