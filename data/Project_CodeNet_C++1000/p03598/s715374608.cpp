#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define pb push_back
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, x;
	cin >> n;
	cin >> k;
	vector<int> co;
	for(int i=0; i<n; i++){
		cin >> x;
		co.pb(x);
	}
	int first = 0, second = 0;
	int todi = 0;
	for(int i=0; i<n; i++){
		first = 2*co[i];
		second = 2*abs(co[i]-k);
		todi += min(first, second);
	}
	cout << todi << endl;
	return  0;
}
