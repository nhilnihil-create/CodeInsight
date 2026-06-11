#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,n) for(int i=a; i<n; i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

int main()
{	
	int n;
	cin >> n;
	
	int s = 0,ind=0;
	FOR(i,1, 10000) {
		if (i*(i + 1)/2 > n) {
			s = i*(i + 1) / 2;
			ind = i;
			break;
		}
	}
	
	FOR(i,1,ind+1) {
		if (i == s - n)continue;
		cout << i << endl;
	}
	return	0;
}


