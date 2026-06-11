#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1000000007

int getPrice( int x, int y ){
	return ( ( x - y ) * ( x - y ) );
}

int main(){
	int n;
	cin >> n;
	vector < int > v (n);
	int sm = 0;
	for( int i = 0; i < n; i++ ){
		cin >> v[i];
		sm += v[i];
	}
	int avg1 = sm/n;
	int avg2 = avg1 + 1;
	int cost1 = 0;
	int cost2 = 0;
	for( int i = 0; i < n; i++ ){
		cost1 += getPrice( v[i], avg1 );
		cost2 += getPrice( v[i], avg2 );
	}
	int ans = min( cost1, cost2 );
	cout << ans;
	return 0;
}