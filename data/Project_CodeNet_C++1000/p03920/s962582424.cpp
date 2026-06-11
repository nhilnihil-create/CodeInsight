#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FFOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define rep(i,n) FOR(i,0,n-1)
#define int long long
#define MOD 998244353
#define MAXN  100005
#define P pair<int,int>

int gcd(int a, int b) {return b?gcd(b,a%b):a;}

signed main(){
	
	int n;cin>>n;
	
	int le=1;
	int ri = 1e7;
	
	while(ri-le>1)
	{
		int mid = (ri+le)/2;
		int wa = mid*(mid+1)/2;
		if(wa>=n) ri = mid;
		else le =mid;
	}
	
	int wa = ri*(ri+1)/2;
	FOR(i,1,ri) if(i != wa-n) cout << i << endl;

}