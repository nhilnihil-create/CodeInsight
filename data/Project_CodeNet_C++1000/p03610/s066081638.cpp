#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	string s;
	cin >> s;
	string ans="";
	for(int i=0;i<s.size();i++){
		if(i%2==0)ans+=s[i];
	}
	cout << ans << endl;
	return 0;
}
