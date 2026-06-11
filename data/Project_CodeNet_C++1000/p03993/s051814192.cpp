#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[a[i]]==i)cnt++;
	}
	cout << cnt/2 << endl;
	return 0;
}
