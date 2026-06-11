#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	int n;
	int numa=0;
	int numb=0;
	int ans=0;
	n=str.size();
	for (int i=0; i<n; i++){
		numa++;
		if(str.at(i)=='A') break;
	}
	reverse(str.begin(), str.end());
	for (int i=0; i<n; i++){
		numb++;
		if(str.at(i)=='Z') break;
	}
	ans = n-numa-numb+2;
	cout << ans << endl;
}
