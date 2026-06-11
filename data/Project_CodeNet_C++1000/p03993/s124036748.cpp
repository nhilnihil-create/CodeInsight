#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e6+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]--;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(i==a[a[i]])cnt++;
	}
	cnt/=2;
	cout << cnt << endl;
}
