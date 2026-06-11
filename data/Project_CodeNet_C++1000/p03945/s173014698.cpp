#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	string s;
	cin >> s;
	int n=s.size();
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1])continue;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
