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
	long long q,h,s,d;
	cin >> q >> h >> s >> d;
	long long n;
	cin >> n;
	long long min_1=min(4*q,min(2*h,s));
	long long min_2=min(2*min_1,d);
	long long ans=(n/2)*min_2+(n%2)*min_1;
	cout << ans << endl;
	return 0;
}
