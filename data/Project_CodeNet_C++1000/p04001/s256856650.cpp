#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<bitset>

using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

signed main()
{
	string str;
	cin >> str;
	vector<int> arr(str.size());
	REP(i, str.size()){
		arr[i] = (int)str[i]- 48;
	}
	int maxbit = 1<<(str.size()-1);
	ll sum=0;
	for(int i=0; i<maxbit; i++){
		bitset<9> tmp(i);
		ll num=arr[0];
		for(int k=1; k<str.size(); k++){
			if(tmp[k-1]){
				sum += num;
				num = arr[k];
			}else{
				num = num*10 + arr[k];
			}
		}
		sum += num;
	}
	cout << sum << endl;
}
