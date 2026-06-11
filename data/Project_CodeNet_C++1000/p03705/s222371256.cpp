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

int main() {
	long long n,a,b;
	cin >> n >> a >> b;
	long long ans = (n-2)*(b-a)+1;
	if(ans<0)ans=0;
	cout << ans << endl;
	return 0;
}

