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

const long long INFL = 1e17+7;
const long long INFI = 1e9+7;
const long long MOD = 1e9+7;
const double EXP = 1e-8;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<long long> ans; 
	long long x,y;
	cin >> x >> y;
	//1
	long long as_1=y-x;
	if(as_1>0){
		ans.push_back(as_1);
	}
	//2
	long long as_2=y-(-x)+1;
	if(as_2>0){
		ans.push_back(as_2);
	}
	//3
	long long as_3=(-y)-x+1;
	if(as_3>0){
		ans.push_back(as_3);
	}
	//4
	long long as_4=(-y)-(-x)+2;
	if(as_4>0){
		ans.push_back(as_4);
	}	
	
	sort(ans.begin(),ans.end());
	cout << ans[0] << endl;
	return 0;
}
